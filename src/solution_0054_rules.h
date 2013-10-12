/**********************************
*  solution_0054_judge.h          *
**********************************/
#pragma once
#include <iostream>
#include <cassert>
#include <string>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::vector;
using std::sort;
class card {
public:
    enum value {
        V2 = 2, V3, V4, V5, V6, V7, V8, V9, VT, VJ, VQ, VK, VA
    } v;
    enum suit {
        SC = 1, SD, SH, SS
    } s;
    card(string::iterator& iter) {
        const char pv = *(iter++);
        const char ps = *iter++;
        iter++;
        if ('2' <= pv and pv <= '9') v = (value) (pv - '2' + V2);
        else if (pv == 'T') v = VT;
        else if (pv == 'J') v = VJ;
        else if (pv == 'Q') v = VQ;
        else if (pv == 'K') v = VK;
        else if (pv == 'A') v = VA;
        else assert(0);
        if (ps == 'C') s = SC;
        else if (ps == 'D') s = SD;
        else if (ps == 'H') s = SH;
        else if (ps == 'S') s = SS;
        else assert(0);
    }
    friend ostream& operator<<(ostream& os, const card& c) {
        return os << "(" << c.v << ", " << c.s << ")";
    }
    bool operator<(const card& other) const {
        return v < other.v;
    }
/*    bool operator==(const card& other) const {
        return v == other.v and s = other.s;
    }*/
};
class hand {
public:
    vector<card> cards;
    hand(string::iterator& iter) {
        for (int i = 0; i < 5; i++) {
            cards.push_back(card(iter));
        }
        sort(cards.begin(), cards.end());
    }
    friend ostream& operator<<(ostream& os, const hand& h) {
        vector<card>::const_iterator i = h.cards.begin();
        os << "{" << *i++;
        while(i != h.cards.end())
            os << ", " << *i++;
        return os << "}";
    }
};
class judge {
public:
    int straight_flush(hand** hands) {
        int top[2];
        for (int i = 0; i < 2; i++) {
            top[i] = 0;
            vector<card>& cards = hands[i]->cards;
            int consecutive = 1;
            for (int j = 1; j < 5; j++) {
                if (cards[j - 1].s == cards[j].s)
                    consecutive++;
                else
                    consecutive = 1;
            }
            if (consecutive != 5) continue;
            if (cards[0].v + 1 != cards[1].v) continue;
            if (cards[1].v + 1 != cards[2].v) continue;
            if (cards[2].v + 1 != cards[3].v) continue;
            if (cards[3].v + 1 != cards[4].v and
                (cards[0].v != card::V2 or cards[4].v != card::VA))
                    continue;
            if (cards[0].v == card::V2 and cards[4].v == card::VA)
                top[i] = card::V5;
            else
                top[i] = cards[4].v;
        }
        if (top[0]) {
            if (top[1]) {
                return top[0] > top[1] ? 1 : 2;
            } else {
                return 1;
            }
        } else {
            if (top[1]) {
                return 2;
            } else {
                return 0;
            }
        }
    }
    int straight(hand** hands) {
        int top[2];
        for (int i = 0; i < 2; i++) {
            top[i] = 0;
            vector<card>& cards = hands[i]->cards;
            if (cards[0].v + 1 != cards[1].v) continue;
            if (cards[1].v + 1 != cards[2].v) continue;
            if (cards[2].v + 1 != cards[3].v) continue;
            if (cards[3].v + 1 != cards[4].v and
                (cards[0].v != card::V2 or cards[4].v != card::VA)) continue;
            if (cards[0].v == card::V2 and cards[4].v == card::VA)
                top[i] = card::V5;
            else top[i] = cards[4].v;
        }
        if (top[0]) {
            if (top[1]) {
                return top[0] > top[1] ? 1 : 2;
            } else {
                return 1;
            }
        } else {
            if (top[1]) {
                return 2;
            } else {
                return 0;
            }
        }
    }
    int flush(hand** hands) {
        int top[2];
        for (int i = 0; i < 2; i++) {
            vector<card>& cards = hands[i]->cards;
            top[i] = 1;
            for (int j = 1; j < 5; j++) {
                if (cards[0].s != cards[j].s) {
                    top[i] = 0;
                    break;
                }
            }
        }
        if (top[0]) {
            if (top[1]) {
                return high_card(hands);
            } else {
                return 1;
            }
        } else {
            if (top[1]) {
                return 2;
            } else {
                return 0;
            }
        }
    }
    int four_of_a_kind(hand** hands) {
        int top[2];
        for (int i = 0; i < 2; i++) {
            vector<card>& cards = hands[i]->cards;
            top[i] = 0;
            int consecutive = 1;
            for (int j = 1; j < 5; j++) {
                if (cards[j - 1].v == cards[j].v) {
                    consecutive++;
                } else {
                    consecutive = 1;
                }
                if (consecutive == 4) {
                    top[i] = cards[j].v;
                }
            }
        }
        if (top[0]) {
            if (top[1]) {
                return top[0] > top[1] ? 1 : 2;
            } else {
                return 1;
            }
        } else {
            if (top[1]) {
                return 2;
            } else {
                return 0;
            }
        }
    }
    int full_house(hand** hands) {
        int top[2];
        for (int i = 0; i < 2; i++) {
            vector<card>& cards = hands[i]->cards;
            top[i] = 0;
            bool has_pair = false;
            int consecutive = 1;
            for (int j = 1; j < 5; j++) {
                if (cards[j - 1].v == cards[j].v) {
                    consecutive++;
                } else {
                    if (consecutive == 2)
                        has_pair = true;
                    if (consecutive == 3)
                        top[i] = cards[j - 1].v;
                    consecutive = 1;
                }
            }
            if (consecutive != 2)
                top[i] = 0;
            if (consecutive == 3 and has_pair)
                top[i] = cards[4].v;
        }
        if (top[0]) {
            if (top[1]) {
                return top[0] > top[1] ? 1 : 2;
            } else {
                return 1;
            }
        } else {
            if (top[1]) {
                return 2;
            } else {
                return 0;
            }
        }
    }
    int three_of_a_kind(hand** hands) {
        int top[2];
        for (int i = 0; i < 2; i++) {
            vector<card>& cards = hands[i]->cards;
            top[i] = 0;
            int consecutive = 1;
            for (int j = 1; j < 5; j++) {
                if (cards[j - 1].v == cards[j].v) {
                    consecutive++;
                } else {
                    consecutive = 1;
                }
                if (consecutive == 3) {
                    top[i] = cards[j].v;
                }
                if (consecutive > 3) {
                    top[i] = 0;
                }
            }
        }
        if (top[0]) {
            if (top[1]) {
                return top[0] > top[1] ? 1 : 2;
            } else {
                return 1;
            }
        } else {
            if (top[1]) {
                return 2;
            } else {
                return 0;
            }
        }
    }
    int two_pairs(hand** hands) {
        int top[2];
        for (int i = 0; i < 2; i++) {
            vector<card>& cards = hands[i]->cards;
            top[i] = 0;
            bool has_pair = false;
            int consecutive = 1;
            for (int j = 1; j < 5; j++) {
                if (cards[j - 1].v == cards[j].v) {
                    consecutive++;
                } else {
                    consecutive = 1;
                }
                if (consecutive == 2) {
                    if (has_pair) {
                        if (top[i] < cards[j].v)
                            top[i] = cards[j].v;
                        has_pair = false;
                    } else {
                        has_pair = true;
                        top[i] = cards[j].v;
                    }
                }
                if (consecutive > 2) {
                    has_pair = false;
                    top[i] = 0;
                }
            }
            if (has_pair)
                top[i] = 0;
        }
        if (top[0]) {
            if (top[1]) {
                return top[0] > top[1] ? 1 : 2;
            } else {
                return 1;
            }
        } else {
            if (top[1]) {
                return 2;
            } else {
                return 0;
            }
        }
    }
    int one_pair(hand** hands) {
        int top[2];
        for (int i = 0; i < 2; i++) {
            vector<card>& cards = hands[i]->cards;
            top[i] = 0;
            int consecutive = 1;
            for (int j = 1; j < 5; j++) {
                if (cards[j - 1].v == cards[j].v) {
                    consecutive++;
                } else {
                    consecutive = 1;
                }
                if (consecutive == 2) {
                    top[i] = cards[j].v;
                }
                if (consecutive > 2) {
                    top[i] = 0;
                }
            }
        }
        if (top[0]) {
            if (top[1]) {
                return top[0] > top[1] ? 1 : 2;
            } else {
                return 1;
            }
        } else {
            if (top[1]) {
                return 2;
            } else {
                return 0;
            }
        }
    }
    int high_card(hand** hands) {
        for (int i = 4; i >= 0; i--) {
            if (hands[0]->cards[4].v > hands[1]->cards[4].v)
                return 1;
            if (hands[0]->cards[4].v < hands[1]->cards[4].v)
                return 2;
        }
        return 0;
    }
    
    int operator()(string hand_str) {
        string::iterator iter = hand_str.begin();
        hand h1(iter);
        hand h2(iter);
        hand* hands[2] = {&h1, &h2};
        int i = straight_flush(hands);
        if (i) return i;
        i = four_of_a_kind(hands);
        if (i) return i;
        i = full_house(hands);
        if (i) return i;
        i = flush(hands);
        if (i) return i;
        i = straight(hands);
        if (i) return i;
        i = three_of_a_kind(hands);
        if (i) return i;
        i = two_pairs(hands);
        if (i) return i;
        i = one_pair(hands);
        if (i) return i;
        i = high_card(hands);
        if (i) return i;
        return 0;
    }
};
