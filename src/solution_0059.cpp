/**********************************
*  solution_0059.cpp              *
**********************************/
#include "solution_0059.h"
#include "solution_0059_data.h"
#include <algorithm>
#include <vector>
using std::sort;
using std::vector;
Solution0059 s0059;
Solution0059::Solution0059() : Solution(59, this) {};
char get_most_common_char(vector<char> vec) {
    sort(vec.begin(), vec.end());
    char result = -1;
    unsigned n = 0;
    unsigned consec = 1;
    for (unsigned i = 1; i < vec.size(); i++) {
        if (vec[i] == vec[i - 1]) {
            consec++;
        } else {
            if (n < consec) {
                n = consec;
                result = vec[i - 1];
            }
            consec = 1;
        }
    }
    if (n < consec) {
        n = consec;
        result = *vec.rbegin();
    }
    return result;
}
answer_t Solution0059::get_answer() {
    const unsigned keyc = 3;
    const char sep = ' ';
    // decryption is a three-step process
    // 1. split the data into 3 parts
    vector<char> split[keyc];
    for (unsigned i = 0, j = 0; i < cipherc; i++, j = (j + 1) % keyc)
        split[j].push_back(cipher[i]);
    // 2. decrypt each part
    vector<char> split_decrypted[keyc];
    for (unsigned i = 0; i < keyc; i++) {
        char most_common = get_most_common_char(split[i]);
        char key = most_common ^ sep;
        for (unsigned j = 0; j < split[i].size(); j++) {
            split_decrypted[i].push_back(char(split[i][j] ^ key));
        }
    }
    // 3. merge the three parts back together
    vector<char> merge(cipherc);
    {
        unsigned j = 0, k = 0;
        for (unsigned i = 0; i < cipherc; i++) {
            merge[i] = split_decrypted[j][k];
            j = (j + 1) % keyc;
            if (j == 0) k++;
        }
    }
/*    for (unsigned i = 0; i < cipherc; i++) {
        cout << merge[i];
    }
    cout << endl;*/
    answer_t answer = 0;
    for (unsigned i = 0; i < cipherc; i++)
        answer += merge[i];
    return answer;
}


