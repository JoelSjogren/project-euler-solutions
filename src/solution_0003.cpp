/**********************************
*  solution_0003.cpp              *
**********************************/
#include "solution_0003.h"
#include <iostream>
using std::cout;
using std::endl;
Solution0003 s0003;
Solution0003::Solution0003() : Solution(3, this) {};
answer_t Solution0003::get_answer() {
    typedef unsigned long long mytype;
    mytype composed = 600851475143;
    for (mytype i = 2; i < composed; i++)
        if (composed % i == 0)
            composed /= i--;
    return composed;
}
