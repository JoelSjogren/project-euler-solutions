/**********************************
*  solution_0072.cpp              *
**********************************/
#include "solution_0072.h"
#include <cassert>
#include <vector>
#include <cmath>
#include <iostream>
#include <set>
using std::cout;
using std::endl;
Solution0072 s0072;
Solution0072::Solution0072() : Solution(72, this) {};
/*
int gcd(int a, int b) {
	// ensure a <= b by swapping
	if (a > b) {
		int tmp = a;
		a = b;
		b = tmp;
	}
	// base case
	assert(b != 0);
	if (a == 0) return b;
	// recursive step. this could be optimized
	while (a <= b) b -= a;
	return gcd(b, a);
}
*/
typedef std::vector<int> list_t;
list_t factorize(int n) {
	assert(1 <= n);
	list_t result;
	// warning: using floating-point arithmetic (sqrt)
	for (int i = 2; n != 1 and i <= sqrt(n) + 1; i++) {
		while (n % i == 0) {
			result.push_back(i);
			n /= i;
		}
	}
	if (n != 1) {
		result.push_back(n);
		//n /= n;
	}
	return result;
}
typedef std::set<int> set_t;
set_t divisors(int n) {
	list_t list = factorize(n);
	return set_t(list.begin(), list.end());
}
// Euler's totient function
int phi(int n) {
	answer_t result = n;
	set_t div = divisors(n);
	for (set_t::iterator it = div.begin();
		 it != div.end(); it++) {
		result *= *it - 1;
	}
	for (set_t::iterator it = div.begin();
		 it != div.end(); it++) {
		assert(result % *it == 0);
		result /= *it;
	}
	return static_cast<int>(result);
}
answer_t Solution0072::get_answer() {
/*    answer_t count = 0;
    const int max = 1000 * 10;
    for (int d = 1; d <= max; d++) {
    	for (int n = 1; n < d; n++) {
    		if (gcd(n, d) == 1) count++;
    	}
    }
    return count;*/
/*    for (int f = 1; f < 10; f++) {
    	cout << "f: " << f << endl;
		list_t l = factorize(f);
		for (size_t i = 0; i < l.size(); i++) {
			cout << "  " << l[i] << endl;
		}
	}*/
	answer_t count = 0;
    const int max = 1000 * 1000;
    for (int d = 2; d <= max; d++) {
    	count += phi(d);
    }
    return count;
}











