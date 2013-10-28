/**********************************
*  solution_0063.cpp              *
**********************************/
#include "solution_0063.h"
#include <set>
#include <gmpxx.h>
using std::set;
Solution0063 s0063;
Solution0063::Solution0063() : Solution(63, this) {};
answer_t Solution0063::get_answer() {
    set<mpz_class> powerful;
    for (mpz_class i = 1; i < 10; i++) {
        for (mpz_class min = 1, prod = i; min <= prod;
             min *= 10, prod *= i) {
            powerful.insert(prod);
        }
    }
    return powerful.size();
}
