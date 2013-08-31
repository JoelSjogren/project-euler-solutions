/**********************************
*  solution.h                     *
*                                 *
*  Prints answer to problems.     *
**********************************/
#pragma once
#include <iosfwd>
#include <map>
typedef unsigned long long answer_t;
class Solution;
typedef std::map<int, Solution*> solutions_t;
class Solution {
    static solutions_t solutions;
    Solution(const Solution& hidden);
    void operator=(const Solution& hidden);
protected:
    Solution(int pproblem_number, Solution* psolution);    
    virtual answer_t get_answer();
    const int problem_number;
public:
    static const int ALL = -1;
    static const int NONE = -2;
    Solution(int pproblem_number) : problem_number(pproblem_number) {}
    friend std::ostream& operator<<(std::ostream& os, Solution& s);
    virtual ~Solution() {}
};
