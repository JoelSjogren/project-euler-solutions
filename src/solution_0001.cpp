/**********************************
*  solution_0001.cpp              *
**********************************/
#include "solution_0001.h"
Solution0001 s0001;
Solution0001::Solution0001() : Solution(1, this) {};
answer_t Solution0001::get_answer() {
    answer_t answer = 0;
    for (int i = 0; i < 1000; i++)
        if (i % 3 == 0 || i % 5 == 0)
            answer += i;
    return answer;
}
