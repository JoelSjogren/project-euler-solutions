/**********************************
*  solution_2.cpp                 *
**********************************/
#include "solution_2.h"
Solution2 s2;
Solution2::Solution2() : Solution(2, this) {};
class FibGen {
    int a, b;
public:
    FibGen(int pa=0, int pb=1) : a(pa), b(pb) {}
    int operator()() {
        int result = a;
        int tmp = a + b;
        a = b;
        b = tmp;
        return result;
    }
};
answer_t Solution2::get_answer() {
    answer_t answer = 0;
    int term;
    FibGen gen;
    while ((term = gen()) <= 4000000)
        if (term % 2 == 0)
            answer += term;
    return answer;
}
