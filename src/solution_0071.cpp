/**********************************
*  solution_0071.cpp              *
**********************************/
#include "solution_0071.h"
#include <iostream>
using std::cout;
using std::endl;
Solution0071 s0071;
Solution0071::Solution0071() : Solution(71, this) {};
answer_t Solution0071::get_answer() {
	int bestN = 0;
	int bestD = 1;
	int n = 0;
	for (int d = 1; d <= 1000 * 1000; d++) {
		while (7 * n < 3 * d) n++; // find least n/d such that n/d >= 3/7
		n--;
		// new guess: n/d
		if (n * bestD > d * bestN) { // if 3/7 - n/d < 3/7 - bestN/bestD
			bestN = n;
			bestD = d;
		}
	}
    return bestN;
}
