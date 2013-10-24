/**********************************
*  is_prime.cpp                   *
**********************************/
#include "is_prime.h"
#include <cmath>
bool is_prime(answer_t pp) {
    if (pp < 2) return false;
    if (pp == 2) return true;
    const answer_t sqrt_pp = int(ceil(sqrt(double(pp))));
    for (answer_t i = 2; i <= sqrt_pp; i++)
        if (pp % i == 0) return false;
    return true;
}
