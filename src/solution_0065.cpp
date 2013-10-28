/**********************************
*  solution_0065.cpp              *
**********************************/
#include "solution_0065.h"
#include <iostream>
#include <gmpxx.h>
using std::cout;
using std::endl;
Solution0065 s0065;
Solution0065::Solution0065() : Solution(65, this) {};
mpz_class sum_of_digits(mpz_class num) {
    mpz_class result = 0;
    while (0 < num) {
        result += num % 10;
        num /= 10;
    }
    return result;
}
answer_t Solution0065::get_answer() {
//    cout << "begin" << endl;
    mpq_class a(0);
//    cout << "constructed" << endl;
    for (int i = (100 - 1) / 3 * 2; 0 < i; i -= 2) {
//        cout << "i: " << i << endl;
        a = 1 / (1 + a);
        a = 1 / (i + a);
        a = 1 / (1 + a);
    }
    a += 2;
    return sum_of_digits(a.get_num()).get_si();
}


