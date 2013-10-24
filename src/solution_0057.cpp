/**********************************
*  solution_0057.cpp              *
**********************************/
#include "solution_0057.h"
#include <gmpxx.h>
#include <iostream>
using std::cout;
using std::endl;
Solution0057 s0057;
Solution0057::Solution0057() : Solution(57, this) {};
answer_t Solution0057::get_answer() {
    answer_t answer = 0;
    mpz_class y = 3;
    mpz_class z = 2;
    mpz_class mark = 1;
    for (int i = 1; i < 1000; i++) {
        mpz_class tmpy = y + 2 * z;
        mpz_class tmpz = y + z;
        y = tmpy;
        z = tmpz;
        mpz_class yz_gcd;
        mpz_gcd(yz_gcd.get_mpz_t(), y.get_mpz_t(), z.get_mpz_t());
        if (yz_gcd != 1) {
            cout << "!: " << yz_gcd << endl;
        }
        y /= yz_gcd;
        z /= yz_gcd;
        if (mark <= z) {
            mark *= 10;
        }
        if (mark <= y) {
            answer++;
        }
    }
    return answer;
}
