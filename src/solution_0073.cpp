/**********************************
*  solution_0073.cpp              *
**********************************/
#include "solution_0073.h"
#include <set>
#include <cassert>
#include <iostream>
using std::cout;
using std::endl;
Solution0073 s0073;
Solution0073::Solution0073() : Solution(73, this) {};
// fraction class with no guarantees that gcd(num, den) == 1
class Fraction {
public:
	int num, den;
	Fraction(int pNum, int pDen) : num(pNum), den(pDen) {
		assert(0 <= num);
		assert(0 <= den);
	}
	bool operator==(const Fraction& other) const {
		return num * other.den == den * other.num;
	}
	bool operator<=(const Fraction& other) const {
		return num * other.den <= den * other.num;
	}
	bool operator<(const Fraction& other) const {
		return num * other.den < den * other.num;
	}
/*	friend std::ostream& operator<<(std::ostream& os,
		 const Fraction& fraction) {
		return os << fraction.num << "/" << fraction.den;
	}*/
};
answer_t Solution0073::get_answer() {
	answer_t count = 0;
	std::set<Fraction> counted;
	const Fraction third(1, 3);
	const Fraction half(1, 2);
	const int maxD = 12 * 1000;
	for (int d = 1; d <= maxD; d++) {
		int minN = d / 3; // max n given that n/d <= 1/3
		int maxN = d / 2; // max n given that n/d <= 1/2
		for (int n = minN; n <= maxN; n++) {
			const Fraction nd(n, d);
			if (nd <= third or half <= nd) continue;
			if (counted.count(nd) == 1) continue;
			count++;
			counted.insert(nd);
		}
	}
/*	for (std::set<Fraction>::iterator it = counted.begin();
		 it != counted.end(); it++) {
		cout << *it << endl;
	}*/
    return count;
}
