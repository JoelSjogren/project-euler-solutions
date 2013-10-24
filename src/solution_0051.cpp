/**********************************
*  solution_0051.cpp              *
**********************************/
#include "solution_0051.h"
#include "is_prime.h"
#include <cmath>
#include <iostream>
#include <iomanip>
using std::cout;
using std::endl;
using std::setfill;
using std::setw;
using std::flush;
Solution0051 s0051;
Solution0051::Solution0051() : Solution(51, this) {};
void print_array(int* i, int n) {
    if (n == 0) cout << "[]";
    cout << "[" << i[0];
    for (int j = 1; j < n; j++)
        cout << ", " << i[j];
    cout << "]" << flush;
}
class b_generator {
    b_generator(const b_generator&);
    void operator=(const b_generator&);
public:
    const int digc;
    int* const digs; // worth 1, 10, 100, etc.
    answer_t val;
    b_generator(int* pdigs, int pdigc) : digc(pdigc), digs(pdigs) {
        for (int i = 0; i < digc; i++)
            digs[i] = 0;
        val = 0;
    }
    bool operator++(int) {
        if (digs[digc - 1] == 1) return false;
        int i = 1, j = 10;
        while (true) {
            if (digs[i] == 0) {
                digs[i] = 1;
                val += j;
                break;
            } else /* if (digs[i] == 1) */ {
                digs[i] = 0;
                val -= j;
                i++;
                j *= 10;
            }
        }
        if (digs[digc - 1] == 1) return false;
        return true;
    }
};
class a_generator {
    a_generator(const a_generator&);
    void operator=(const a_generator&);
public:
    const int digc;
    int* const digs;
    answer_t val;
    const b_generator& b;
    a_generator(int* pdigs, int pdigc, const b_generator& pb)
        : digc(pdigc), digs(pdigs), b(pb) {
        for (int i = 0; i < digc; i++)
            digs[i] = 0;
        val = 0;
    }
    bool operator++(int) {
        if (digs[digc - 1] == 1) return false;
        // TODO optimize by letting last digit (#0) be only 1, 3, 7, 9?
        for (int i = 0, j = 1; true; i++, j *= 10) {
            if (b.digs[i] == 1) {
                continue;
            }
            if (digs[i] != 9) {
                digs[i]++;
                val += j;
                break;
            } else /* if (digs[i] == 9) */ {
                digs[i] = 0;
                val -= j * 9;
            }
        }
        if (digs[digc - 1] == 1) return false;
        return true;
    }
};
answer_t Solution0051::get_answer() {
    answer_t answer = -1; // max
    const int digc = 7;
    int a_back[digc];
    int b_back[digc];
    b_generator b(b_back, digc);
    while (b++) { // first value is 0. discard
//        cout << "b: " << setfill('0') << setw(digc) << b.val << endl;
        a_generator a(a_back, digc, b);
        while (a++) { // first value is 0. discard
            if (answer < a.val) break;
            // Test family
            int prime_count = 0;
            answer_t first_prime = 0;
            for (int j = a.val < b.val ? 1 : 0; j < 10; j++) {
                if (is_prime(a.val + b.val * j)) {
                    prime_count++;
                    if (first_prime == 0)
                        first_prime = a.val + b.val * j;
                }
            }
            if (prime_count >= 8) answer = first_prime;
        }
    }
    return answer;
}




