/**********************************
*  solution_0006.cpp              *
**********************************/
#include "solution_0006.h"
Solution0006 s0006;
Solution0006::Solution0006() : Solution(6, this) {};
answer_t Solution0006::get_answer() {
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
