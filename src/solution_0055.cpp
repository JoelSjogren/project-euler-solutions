/**********************************
*  solution_0055.cpp              *
**********************************/
#include "solution_0055.h"
#include <iostream>
#include <cstring>
using std::cout;
using std::endl;
Solution0055 s0055;
Solution0055::Solution0055() : Solution(55, this) {};
bool is_palindrome(int* digits, int digitc) {
    if (digits[0] == 0) {
        for (int i = 0; i < digitc; i++)
            if (digits[i] != 0)
                return false;
        return true;
    }
    int last = digitc - 1;
    while (digits[last] == 0) last--;
    for (int i = 0; i < (last + 1) / 2; i++)
        if (digits[i] != digits[last - i])
            return false;
    return true;
}
void sum_backwards(int* from, int* to, int digitc) {
    int last = digitc - 1;
    while (from[last] == 0) last--;
    for (int i = 0; i <= last; i++)
        to[i] = from[i] + from[last - i];
    for (int i = 0; i <= last; i++) {
        if (to[i] >= 10) {
            to[i] -= 10;
            to[i + 1]++;
        }
    }
}
bool is_lychrel(int* digits1, int* digits2, int digitc) {
    bool verbose = (digits1[0] == 7 and digits1[1] == 4);
    const int max_iter = 50;
    for (int i = 0; i < max_iter / 2; i += 2) {
        sum_backwards(digits1, digits2, digitc);
        if (is_palindrome(digits2, digitc))
            return false;
        sum_backwards(digits2, digits1, digitc);
        if (is_palindrome(digits1, digitc))
            return false;
    }
    return true;
}
void increment(int* digits, int digitc) {
    digits[0]++;
    for (int i = 0; digits[i] >= 10; i++) {
        digits[i] -= 10;
        digits[i + 1]++;
    }
}
void print_digits(int* digits, int digitc) {
    if (digitc == 0) {
        cout << "[]";
        return;
    }
    cout << "[" << digits[0];
    for (int i = 1; i < digitc; i++)
        cout << digits[i];
    cout << "]";
}
answer_t Solution0055::get_answer() {
    const int digitc = 64; // a little more than is_lychrel::max_iter
    int digits1[digitc] = { 0 };
    int digits2[digitc] = { 0 };
    int digits3[digitc] = { 0 };
    int zero[digitc] = { 0 };
    answer_t answer = 0;
    for (int i = 0; i < 10000; i++, increment(digits1, digitc)) {
//        print_digits(digits1, digitc);
        memcpy(digits2, digits1, sizeof(digits1));
        memcpy(digits3, zero, sizeof(zero));
        if (is_lychrel(digits2, digits3, digitc)) {
//            cout << "L";
            answer++;
        }
//        cout << endl;
    }
    return answer;
}





