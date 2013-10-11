/**********************************
*  solution_0012.cpp              *
**********************************/
#include "solution_0012.h"
Solution0012 s0012;
Solution0012::Solution0012() : Solution(12, this) {};
int divisors(answer_t n) {
    int result = 1;
    answer_t incr = 1;
    for (answer_t i = 2; i <= n; i += incr) {
        if (n % i == 0) {
            answer_t prim = i / incr;
            int fact = 1;
            incr = i;
            for (answer_t j = i * prim; n % j == 0; j *= prim) {
                fact++;
                incr *= prim;
                i *= prim;
            }
            result *= fact + 1;
        }
    }
    return result;
}
answer_t Solution0012::get_answer() {
    for (answer_t t = 1, add = 2; true; t += add, add++) {
        answer_t divc = divisors(t);
        if (500 < divc)
            return t;
    }
    return 0;
}
