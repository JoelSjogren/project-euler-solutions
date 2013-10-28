/**********************************
*  solution_0062.cpp              *
**********************************/
#include "solution_0062.h"
#include <cassert>
#include <map>
#include <utility>
#include <iostream>
using std::cout;
using std::endl;
using std::ostream;
using std::make_pair;
Solution0062 s0062;
Solution0062::Solution0062() : Solution(62, this) {};
class digit_count {
    unsigned back[10];
public:
    digit_count() {
        for (int i = 0; i < 10; i++)
            back[i] = 0;
    }
    digit_count(answer_t num) {
        assert(num != 0);
        for (int i = 0; i < 10; i++)
            back[i] = 0;
        while (num != 0) {
            back[num % 10]++;
            num /= 10;
        }
    }
    bool operator<(const digit_count& other) const {
        for (int i = 0; i < 10; i++) {
            if (back[i] < other.back[i]) return true;
            if (back[i] > other.back[i]) return false;
        }
        return false;
    }
    bool operator==(const digit_count& other) const {
        for (int i = 0; i < 10; i++) {
            if (back[i] != other.back[i]) return false;
        }
        return true;
    }
    friend ostream& operator<<(ostream& os, const digit_count& other) {
        os << "[" << other.back[0];
        for (int i = 1; i < 10; i++)
            os << "," << other.back[i];
        return os << "]";
    }
};
typedef std::pair<digit_count, int> pair_t;
typedef std::map<digit_count, int> map_t;
ostream& operator<<(ostream& os, const pair_t& other) {
    return os << "(" << other.first << ", " << other.second << ")";
}
ostream& operator<<(ostream& os, const map_t& other) {
    map_t::const_iterator it = other.begin();
    if (it == other.end()) return os << "[]";
    os << "[" << *it++;
    while (it != other.end())
        os << ", " << *it++;
    return os << "]";
}
answer_t Solution0062::get_answer() {
    map_t counts;
    const int permutations = 5;
    digit_count solution_count;
    for (answer_t i = 1; true; i++) {
        digit_count count(i * i * i);
        map_t::iterator it = counts.find(count);
        if (it == counts.end()) {
            counts.insert(make_pair(count, 1));
        } else {
            it->second++;
            if (it->second == permutations) {
                solution_count = it->first;
                break;
            }
        }
    }
    for (answer_t i = 1; true; i++) {
        digit_count count(i * i * i);
        if (count == solution_count) return i * i * i;
    }
}









