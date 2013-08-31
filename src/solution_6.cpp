/**********************************
*  solution_6.cpp                 *
**********************************/
#include "solution_6.h"
Solution6 s6;
Solution6::Solution6() : Solution(6, this) {};
answer_t Solution6::get_answer() {
    answer_t a = 0, b = 0;
    const int max = 100;
    for (int i = 1; i <= max; i++) {
        a += i * i;
    }
    for (int i = 1; i <= max; i++) {
        b += i;
    }
    b = b * b;
    return b - a;
}
