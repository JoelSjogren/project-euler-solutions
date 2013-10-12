/**********************************
*  solution_0054.cpp              *
**********************************/
#include "solution_0054.h"
#include "solution_0054_data.h" // declares hands_str[], handc
#include "solution_0054_rules.h" // defines what poker is, including who wins
Solution0054 s0054;
Solution0054::Solution0054() : Solution(54, this) {};
answer_t Solution0054::get_answer() {
    judge roy;
    answer_t p1_win = 0;
    for (int i = 0; i < handc; i++) {
        int winner = roy(hands_str[i]);
//        cout << "Winner: " << winner << endl;
        if (winner == 1)
            p1_win++;
    }
    return p1_win;
}




