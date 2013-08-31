/**********************************
*  solution.h                     *
**********************************/
#include "solution.h"
#include <iostream>
#include <cassert>
#include <cstdlib>
using std::cout;
using std::endl;
using std::cerr;
using std::pair;
solutions_t Solution::solutions;
template <class T1, class T2>
pair<T1, T2> get_pair(T1 first, T2 second) {
    return pair<T1, T2>(first, second);
}
Solution::Solution(int pproblem_number, Solution* psolution)
    : problem_number(pproblem_number){
    solutions.insert(get_pair(pproblem_number, psolution));
}
void error_cannot_solve() {
    cerr << "E: cannot solve problem" << endl;
    exit(1);
}
answer_t Solution::get_answer() {
    error_cannot_solve();
    exit(1);
}
std::ostream& operator<<(std::ostream& os, Solution& s) {
    if (s.problem_number == Solution::ALL) {
        for (solutions_t::iterator i = Solution::solutions.begin();
             i != Solution::solutions.end(); i++) {
            os << *i->second;
        }
    } else {
        os << "## Problem " << s.problem_number << " ##"
           << endl;
        solutions_t::iterator foundhere =
            Solution::solutions.find(s.problem_number);
        if (foundhere == Solution::solutions.end())
            error_cannot_solve();
        answer_t answer = foundhere->second->get_answer();
        os << "Answer: " << answer << endl;
    }
    return os;
}
