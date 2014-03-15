/**********************************
*  solution_0066.cpp              *
**********************************/
#include "solution_0066.h"
#include <gmpxx.h>
#include <map>
#include <cassert>
#include <utility>
#include <algorithm>
#include <iostream>
using std::cout;
using std::endl;
using std::map;
using std::make_pair;
using std::min_element;
using std::pair;
Solution0066 s0066;
Solution0066::Solution0066() : Solution(66, this) {};
bool is_square(int n) {
    if (n < 0) return false;
    for (int i = 0; i <= n; i++) {
        if (i * i == n) {
            return true;
        }
    }
    return false;
}
int isqrt(int n) {
    assert(0 <= n);
    for (int i = 0; i <= n; i++) {
        if (i * i == n) {
            return i;
        }
    }
    assert(false);
}
bool less(pair<int, int> a, pair<int, int> b) {
    return a.second < b.second;
}
answer_t Solution0066::get_answer() {/*
    const int dmax = 1000;
    map<int, int> dToX;
    for (int D = 2; D <= dmax; D++) {
//        cout << "D: " << D << endl;
        if (is_square(D)) continue;
        if (D == 61) continue;
        for (mpz_class y = 1; true; y++) {
            if (y % 1000000 == 0) cout << "y == " << y << endl;
            mpz_class x2 = 1 + D * y * y;
            if (mpz_perfect_square_p(x2.get_mpz_t())) {
                mpz_class x;
                mpz_sqrt(x.get_mpz_t(), x2.get_mpz_t());
                dToX.insert(make_pair(D, x.get_si()));
                cout << D << " -> " << x.get_si() << endl;
                break;
            }
        }
    }
    return max_element(dToX.begin(), dToX.end(), less)->first;*/
    return 0;
}



















