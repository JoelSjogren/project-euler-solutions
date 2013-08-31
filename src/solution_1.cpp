/**********************************
*  solution_1.cpp                 *
**********************************/
#include "solution_1.h"
Solution1 s1;
Solution1::Solution1() : Solution(1, this) {};
answer_t Solution1::get_answer() {
    answer_t answer = 0;
    for (int i = 0; i < 1000; i++)
        if (i % 3 == 0 || i % 5 == 0)
            answer += i;
    return answer;
}
