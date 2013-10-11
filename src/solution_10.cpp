/**********************************
*  solution_10.cpp                *
**********************************/
#include "solution_10.h"
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
Solution10 s10;
Solution10::Solution10() : Solution(10, this) {};
/*
bool isPrime(answer_t n) {
    if (n < 2) return false;
    if (n == 2 or n == 3) return true;
    answer_t max = sqrt(n);
    for (answer_t i = 2; i <= max; i++)
        if (n % i == 0)
            return false;
    return true;
}
answer_t Solution10::get_answer() {
    answer_t answer = 0;
    for (answer_t i = 0; i < 2000000; i++)
        if (isPrime(i))
            answer += i;
    return answer;
}
*/
answer_t Solution10::get_answer() {
    const answer_t max = 2000000;
    bool is_prime[max];
    is_prime[0] = false;
    is_prime[1] = false;
    for (answer_t i = 2; i < max; i++)
        is_prime[i] = 1;
    for (answer_t i = 2; i < max; i++)
        if (is_prime[i])
            for (answer_t j = 2 * i; j < max; j += i)
                is_prime[j] = false;
    answer_t answer = 0;
    for (answer_t i = 0; i < max; i++)
        if (is_prime[i])
            answer += i;
/*    cout << std::boolalpha;
    for (answer_t i = 0; i < max; i++)
        cout << i << ": " << is_prime[i] << endl;
    cout << std::noboolalpha;*/
    return answer;
}










