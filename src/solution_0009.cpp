/**********************************
*  solution_0009.cpp              *
**********************************/
#include "solution_0009.h"
#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
Solution0009 s0009;
Solution0009::Solution0009() : Solution(9, this) {};
answer_t Solution0009::get_answer() {
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
