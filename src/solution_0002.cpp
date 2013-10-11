/**********************************
*  solution_0002.cpp              *
**********************************/
#include "solution_0002.h"
Solution0002 s0002;
Solution0002::Solution0002() : Solution(2, this) {};
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
answer_t Solution0002::get_answer() {
    answer_t answer = 0;
    int term;
    FibGen gen;
    while ((term = gen()) <= 4000000)
        if (term % 2 == 0)
            answer += term;
    return answer;
}
