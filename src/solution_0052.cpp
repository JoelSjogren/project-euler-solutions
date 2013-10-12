/**********************************
*  solution_0052.cpp              *
**********************************/
#include "solution_0052.h"
#include <iostream>
using std::ostream;
using std::cout;
using std::endl;
Solution0052 s0052;
Solution0052::Solution0052() : Solution(52, this) {};
class digit_counter {
    int digits[10];
public:
    digit_counter(answer_t value) {
        for (int i = 0; i < 10; i++)
            digits[i] = 0;
        while (value != 0) {
            digits[value % 10]++;
            value /= 10;
        }
    }
    friend ostream& operator<<(ostream& os, const digit_counter& dc) {
        os << "[" << dc.digits[0];
        for (int i = 1; i < 10; i++)
            os << ", " << dc.digits[i];
        os << "]";
        return os;
    }
    bool operator==(const digit_counter& other) {
        for (int i = 0; i < 10; i++)
            if (digits[i] != other.digits[i])
                return false;
        return true;
    }
    bool operator!=(const digit_counter& other) {
        return !operator==(other);
    }
};
answer_t Solution0052::get_answer() {
    for (answer_t i = 1; true; i++) {
        digit_counter d1(i);
        for (answer_t j = 2; true; j++) {
            if (j == 7)
                return i;
            if (d1 != digit_counter(i * j))
                break;
        }
    }
}



