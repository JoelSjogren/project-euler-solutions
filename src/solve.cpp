/**************************
*  solve - math problems  *
*   by Joel Sjögren       *
**************************/
#include "solution.h"
#include <iostream>
#include <cerrno>
#include <cassert>
#include <cstring>
#include <cstdlib>
using std::cout;
using std::endl;
using std::cerr;
void error_exit(int errnum) {
    cerr << "E: " << strerror(errnum) << endl;
    exit(1);
}
int main(int argc, char* argv[]) {
	assert(argc == 1 || argc == 2);
	int number;
    if (argc == 1) {
        number = Solution::ALL;
    }
    if (argc == 2) {
        errno = 0;
        number = atoi(argv[1]);
        if (errno) error_exit(errno);
    }
    Solution solution(number);
    cout << solution;
    cout << "Done!" << endl;
}
