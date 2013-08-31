/**********************************
*  solution_7.cpp                 *
**********************************/
#include "solution_7.h"
#include <cmath>
#include <iostream>
using std::cout;
using std::endl;
Solution7 s7;
Solution7::Solution7() : Solution(7, this) {};
namespace {
    bool is_prime(int pp) {
        if (pp < 2) return false;
        if (pp == 2) return true;
        const int sqrt_pp = int(ceil(sqrt(double(pp))));
        for (int i = 2; i <= sqrt_pp; i++)
            if (pp % i == 0) return false;
        return true;
    }
}
answer_t Solution7::get_answer() {
    const int primec = 10001;
    answer_t answer = 0;
    int primei = 0;
    while (primei < primec) {
        do { answer++; } while (!is_prime(answer));
        primei++;
    }
    return answer;
}
