/**********************************
*  solution_0056.cpp              *
**********************************/
#include "solution_0056.h"
#include <gmpxx.h>
#include <cassert>
Solution0056 s0056;
Solution0056::Solution0056() : Solution(56, this) {};
answer_t digit_sum(mpz_class num) {
    assert(num > 0);
    mpz_class result = 0;
    const mpz_class ten = 10;
    while (num > 0) {
        result += num % ten;
        num /= ten;
    }
    return result.get_si();
}
answer_t Solution0056::get_answer() {
    answer_t answer = 0;
    for (int i = 1; i < 100; i++) {
        mpz_class massive = i;
        for (int j = 1; j < 100; j++) {
            answer_t sum = digit_sum(massive);
            if (answer < sum)
                answer = sum;
            massive *= i;
        }
    }
    return answer;
}
