/**********************************
*  solution_0061.cpp              *
**********************************/
#include "solution_0061.h"
#include <list>
#include <cassert>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iomanip>
using std::setw;
using std::fill;
using std::ostream;
using std::cout;
using std::endl;
Solution0061 s0061;
Solution0061::Solution0061() : Solution(61, this) {};
class number_t {
public:
    char left, right; // in a four-digit number abcd, left = ab etc.
    number_t(int n) {
        assert(1000 <= n and n < 10000);
        left = n / 100;
        right = n % 100;
    }
    operator int() const {
        return left * 100 + right;
    }
};
template <class T, class Alloc=std::allocator<T> >
class figurate : public std::list<T, Alloc> {
//    figurate(const figurate_t&);
public:
    int id;
    figurate& operator=(const figurate& other) {
        std::list<number_t>::operator=(other);
        id = other.id;
        return *this;
    }
    figurate() {
        static int next_id = 0;
        id = next_id++;
    }
    template <class Iterator>
    figurate(Iterator begin, Iterator end)
         : std::list<T, Alloc>(begin, end) {}
    bool operator<(const figurate& other) {
        return id < other.id;
    }
};
typedef figurate<number_t> figurate_t;
template <class T,
    template <class T,
        class=std::allocator<T> > class Container>
std::ostream&
operator<<(std::ostream& os, const Container<T>& cont) {
    typename Container<T>::const_iterator i = cont.begin();
	if (i == cont.end()) return os << "[]";
	os << "[" << *i++;
	for (/* i is set */; i != cont.end(); i++)
		os << ", " << *i;
    os << "]";
	return os;
}
// returns true if a change was made. always does something if it can.
bool intersect(figurate_t& fig1, figurate_t& fig2) {
    // fig1[].right shall be compared with fig2[].left
    bool changed = false;
    { // if not in fig2 then not in fig1
        figurate_t::iterator i = fig1.begin();
        while (i != fig1.end()) {
            figurate_t::iterator j = fig2.begin();
            while (j != fig2.end()) {
                if (i->right == j->left) break;
                j++;
            }
            if (j == fig2.end()) {
                i = fig1.erase(i);
                changed = true;
            } else {
                i++;
            }
        }
    }
    { // if not in fig1 then not in fig2
        figurate_t::iterator j = fig2.begin();
        while (j != fig2.end()) {
            figurate_t::iterator i = fig1.begin();
            while (i != fig1.end()) {
                if (i->right == j->left) break;
                i++;
            }
            if (i == fig1.end()) {
                j = fig2.erase(j);
                changed = true;
            } else {
                j++;
            }
        }
    }
    return changed;
}
figurate_t get_figurate(int func(unsigned)) {
    figurate_t result;
    int i = 0;
    while (func(i) < 1000) {
        i++;
    }
    int val;
    while ((val = func(i)) < 10000) {
        result.push_back(val);
        i++;
    }
    return result;
}
namespace fig {
    int tri(unsigned n) { return n * (1 * n + 1) / 2; }
    int squ(unsigned n) { return n * (1 * n + 0) / 1; }
    int pen(unsigned n) { return n * (3 * n - 1) / 2; }
    int hex(unsigned n) { return n * (2 * n - 1) / 1; }
    int hep(unsigned n) { return n * (5 * n - 3) / 2; }
    int oct(unsigned n) { return n * (3 * n - 2) / 1; }
}
unsigned factorial(unsigned n) {
    assert(n < 10);
    unsigned result = 1;
    while (0 < n) result *= n--;
    return result;
}
answer_t Solution0061::get_answer() {
    typedef std::vector<figurate_t> vector_t;
    vector_t original;
    original.push_back(get_figurate(fig::tri));
    original.push_back(get_figurate(fig::squ));
    original.push_back(get_figurate(fig::pen));
    original.push_back(get_figurate(fig::hex));
    original.push_back(get_figurate(fig::hep));
    original.push_back(get_figurate(fig::oct));
    for (unsigned i = 0; i < factorial(original.size()); i++) {
        vector_t copy = original;
        unsigned consec = 0;
        unsigned i0 = 0;
        unsigned i1 = (i0 + 1) % copy.size();
        while (consec < 6) {
            if (intersect(copy[i0], copy[i1])) {
                consec = 0;
            } else {
                consec++;
            }
            i0 = i1;
            i1 = (i1 + 1) % copy.size();
        }
        if (copy[0].size() == 1) {
            answer_t answer = 0;
            for (unsigned j = 0; j < copy.size(); j++) {
                assert(copy[j].size() == 1);
                answer += *copy[j].begin();
            }
            return answer;
        }
        next_permutation(original.begin(), original.end());
    }
    return 0;
}











