/**********************************
*  solution_0060.cpp              *
**********************************/
#include "solution_0060.h"
#include "is_prime.h"
#include <vector>
#include <cassert>
typedef std::vector<answer_t> vector_t;
Solution0060 s0060;
Solution0060::Solution0060() : Solution(60, this) {};
answer_t concatenate(answer_t a, answer_t b) {
    assert(0 < a and 0 < b);
    answer_t padding = 1;
    while (padding <= b)
        padding *= 10;
    return a * padding + b;
}
bool add_elements(vector_t& vec, unsigned n,
     answer_t min, answer_t max) {
    if (n == 0) return true;
    for (answer_t i = min; i < max; i++) {
        if (is_prime(i)) {
            unsigned j;
            for (j = 0; j < vec.size(); j++) {
                if (!is_prime(concatenate(i, vec[j]))
                     or !is_prime(concatenate(vec[j], i))) {
                    break;
                }
            }
            if (j == vec.size()) {
                vec.push_back(i);
                if (add_elements(vec, n - 1, i + 1, max)) {
                    return true;
                }
                vec.pop_back();
            }
        }
    }
    return false;
}
answer_t Solution0060::get_answer() {
    vector_t vec;
    if (!add_elements(vec, 5, 0, 10000)) return 0;
    answer_t answer = 0;
    for (unsigned i = 0; i < vec.size(); i++) {
        answer += vec[i];
    }
    return answer;
}







