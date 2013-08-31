/**********************************
*  solution_5.cpp                 *
**********************************/
#include "solution_5.h"
#include <cassert>
Solution5 s5;
Solution5::Solution5() : Solution(5, this) {};
bool is_prime(int pp) {
    if (pp < 2) return false;
    for (int i = 2; i < pp; i++)
        if (pp % i == 0)
            return false;
    return true;
}
int divides(int den, int num) {
    int count = 0;
    assert(1 < den);
    while (num % den == 0) {
        num /= den;
        count++;
    }
    return count;
}
int max(int a, int b) { return a > b ? a : b; }
answer_t Solution5::get_answer() {
    const int primes[] = { 2, 3, 5, 7, 11, 13, 17, 19, };
    const int primec = sizeof primes / sizeof *primes;
    int factor_count[primec] = { 0 };
    for (int i = 1; i <= 20; i++) {
        for (int j = 0; j < primec; j++) {
            factor_count[j] = max(factor_count[j],
                                  divides(primes[j], i));
        }
    }
    answer_t answer = 1;
    for (int i = 0; i < primec; i++) {
        for (int j = 0; j < factor_count[i]; j++) {
            answer *= primes[i];
        }
    }
    return answer;
}




