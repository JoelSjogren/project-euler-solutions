/**********************************
*  solution_0078.cpp              *
**********************************/
/*
Because order doesn't matter, the partitions can be represented as maps M: int -> int. M(i) designates the number of groups of length i in the partition. sum(i * M(i)) = n is the total number of coins. That makes the problem a matter of counting all M for n = 1, 2, 3, ... until the number of M's, p(n), is divisible by 1,000,000. Define a new version of p, with an extra parameter m designating the least allowed length of any group in the partition. p(n, m) = p(n, m+1) + p(n-m, m).
*/
#include "solution_0078.h"
#include <cassert>
#include <vector>
Solution0078 s0078;
Solution0078::Solution0078() : Solution(78, this) {};
using std::vector;
answer_t Solution0078::get_answer() {
	for (int max = 1; true; max *= 2) { // 0 <= n < max, 1 <= m < max
		// p0 is column m in a max*max matrix of values of p.
		// p1 is column m+1 in the same matrix.
		// The index into p0, p1 represents n as in p(n, m).
		vector<int> p0(max);
		vector<int> p1(max);
	
		p0[0] = 1; // will always be 1.
		// p1 is now column max - 1
		p1[0] = 1;
		p1[max - 1] = 1;

		for (int m = max - 2; 1 <= m; m--) {
			for (int n = m; n < max; n++) {
				p0[n] = p0[n - m] + p1[n];
				p0[n] %= 1000000; // using additivity of remainder
			}
			p1 = p0;
			// leaving p0 as is. that's ok in this case.
		}
		
		for (int i = 0; i < max; i++) {
			if (p1[i] == 0) {
				return i;
			}
		}
	}
}
/* Third attempt uses too much memory (n^2). I'll keep it as a lesson.
answer_t Solution0078::get_answer() {
	const int max = 10000;
	int** p = new int* [max]; // p(n, m) = p[n][m]. m = 0 is unused.
	for (int i = 0; i < max; i++) {
		p[i] = new int [max];
	}
	// p is normally zero
	for (int n = 0; n < max; n++) {
		for (int m = 0; m < max; m++) {
			p[n][m] = 0;
		}
	}
	// p is one at the first row
	for (int m = 1; m < max; m++) {
		p[0][m] = 1;
	}
	// p is one at the diagonal n = m
	for (int n = 1; n < max; n++) {
		p[n][n] = 1;
	}
	// p(n, m) = p(n, m+1) + p(n-m, m)
	for (int n = 0; n < max; n++) {
		for (int m = n - 1; 1 <= m; m--) {
			p[n][m] = p[n][m+1] + p[n-m][m];
			p[n][m] %= 1000000; // we're only interested in the remainder
		}
	}
	for (int i = 1; i < max; i++) {
		cout << i << ": " << p[i][1] << endl;
		if (p[i][1] == 0) break;
	}
    return 0;
}*/




