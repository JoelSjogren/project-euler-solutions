/**********************************
*  solution_9.cpp                 *
**********************************/
#include "solution_9.h"
#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
Solution9 s9;
Solution9::Solution9() : Solution(9, this) {};
/*namespace {
    bool is_square(int ps) {
        if (ps == 0 || ps == 1) return true;
        for (int i = 0; i < ps; i++)
            if (i * i == ps) return true;
            else if (i * i > ps) return false;
        return false;
    }
    int isqrt(int sq) {
        if (sq == 0) return 0;
        if (sq == 1) return 1;
        for (int i = 0; i < sq; i++)
            if (i * i == sq)
                return i;
        assert(0);
    }
}*/
answer_t Solution9::get_answer() {
    const unsigned sum = 1000;
    for (answer_t i = 1; i < sum; i++) {
        for (answer_t j = i + 1; i + j < sum; j++) {
            answer_t k = sum - i - j;
            if (i * i + j * j == k * k)
                return i * j * k;
        }
    }
    assert(0);
}
