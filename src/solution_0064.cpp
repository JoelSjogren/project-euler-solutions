/**********************************
*  solution_0064.cpp              *
**********************************/
#include "solution_0064.h"
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using std::ostream;
using std::vector;
using std::cout;
using std::endl;
using std::find;
Solution0064 s0064;
Solution0064::Solution0064() : Solution(64, this) {};
class part_t {
public:
    int rr;
    double r;
    int b;
    int a;
    part_t(int prr, double pr, int pb, int pa)
         : rr(prr), r(pr), b(pb), a(pa) {}
    part_t() : rr(-1), r(-1), b(-1), a(-1) {}
    part_t next() const {
        part_t result;
        result.rr = rr;
        result.r = r;
        result.b = (rr - a * a) / b;
        result.a = int(b / (r - a)) * result.b - a;
        return result;
    }
    bool operator==(const part_t& other) const {
        return rr == other.rr and r == other.r
             and b == other.b and a == other.a;
    }
    friend ostream& operator<<(ostream& os, const part_t& part) {
        return os << "(" << part.b << ", " << part.a << ")";
    }
};
ostream& operator<<(ostream& os, const vector<part_t>& vec) {
    if (vec.size() == 0) return os << "[]";
    os << "[" << vec[0];
    for (unsigned i = 1; i < vec.size(); i++)
        os << ", " << vec[i];
    return os << "]";
}
answer_t Solution0064::get_answer() {
    answer_t oddc = 0;
    for (int i = 0; i <= 10000; i++) {
        double r = sqrt(i);
        if (r == int(r)) continue;
        typedef vector<part_t> vector_t;
        vector_t vec;
        vec.push_back(part_t(i, r, 1, int(r)));
        while (true) {
            part_t next = vec.rbegin()->next();
            vector_t::iterator it = find(vec.begin(), vec.end(), next);
            if (it == vec.end()) {
                vec.push_back(next);
            } else {
                if ((vec.end() - it) % 2 == 1) {
                    oddc++;
                }
                break;
            }
        }
    }
    return oddc;
}




