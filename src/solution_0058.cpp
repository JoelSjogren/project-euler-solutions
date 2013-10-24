/**********************************
*  solution_0058.cpp              *
**********************************/
#include "solution_0058.h"
#include "is_prime.h"
Solution0058 s0058;
Solution0058::Solution0058() : Solution(58, this) {};
answer_t Solution0058::get_answer() {
    answer_t side_length = 3;
    answer_t i = 9;
    answer_t primes = 3;
    answer_t non_primes = 2;
    while (non_primes <= 9 * primes) {
        i += side_length + 1;
        if (is_prime(i)) primes++;
        else non_primes++;
        i += side_length + 1;
        if (is_prime(i)) primes++;
        else non_primes++;
        i += side_length + 1;
        if (is_prime(i)) primes++;
        else non_primes++;
        i += side_length + 1;
        if (is_prime(i)) primes++;
        else non_primes++;
        side_length += 2;
    }
    return side_length;
}
