/**********************************
*  solution_3.cpp                 *
**********************************/
#include "solution_3.h"
#include <iostream>
using std::cout;
using std::endl;
Solution3 s3;
Solution3::Solution3() : Solution(3, this) {};
answer_t Solution3::get_answer() {
    typedef unsigned long long mytype;
    mytype composed = 600851475143;
    for (mytype i = 2; i < composed; i++)
        if (composed % i == 0)
            composed /= i--;
    return composed;
}
