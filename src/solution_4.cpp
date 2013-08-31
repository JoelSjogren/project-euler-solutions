/**********************************
*  solution_4.cpp                 *
**********************************/
#include "solution_4.h"
#include <cassert>
Solution4 s4;
Solution4::Solution4() : Solution(4, this) {};
int get_digit(answer_t number, int index) {
    answer_t focus = 1;
    for (int i = 0; i < index; i++) focus *= 10;
    return number % (focus * 10) / focus;
}
int get_digitc(answer_t number) {
    if (number == 0) return 1;
    answer_t focus = 1;
    for (int i = 1; true; i++, focus *= 10)
        if (number / focus < 10)
            return i;
        else if (50 < i) { assert(0); }
}
bool is_palindrome(answer_t number) {
    const int digitc = get_digitc(number);
    for (int i = 0; i < digitc / 2; i++)
        if (get_digit(number, i) != get_digit(number, digitc - 1 - i))
            return false;
    return true;
}
answer_t Solution4::get_answer() {
    answer_t answer = 0;
    const int min = 100, max = 1000;
    for (int i = min; i < max; i++) {
        for (int j = min; j < max; j++) {
            answer_t prod = i * j;
            if (answer < prod && is_palindrome(prod))
                answer = prod;
        }
    }
    return answer;
}
