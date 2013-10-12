/**********************************
*  solution_0053.cpp              *
**********************************/
#include "solution_0053.h"
#include <iostream>
using std::cout;
using std::endl;
Solution0053 s0053;
Solution0053::Solution0053() : Solution(53, this) {};
answer_t Solution0053::get_answer() {
    answer_t answer = 0;
    for (int n = 23; n <= 100; n++) {
        answer_t f = 1; // factorial(n, r)
        for (int r = 0; r <= n; r++) {
            if (1000000 < f) {
                answer += n + 1 - 2 * r; // total in row minus those less
                break;
            }
            // prepare next number
            f *= n - r;
            f /= r + 1;
        }
    }
    return answer;
}
