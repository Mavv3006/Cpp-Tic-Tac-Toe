//
// Created by Marvin on 30.05.2021.
//

#ifndef TIC_TAC_TOE_TICTACTOE_H
#define TIC_TAC_TOE_TICTACTOE_H


#include "CustomArray.h"

class TicTacToe {
public:
    static const int Start = 0;

    static int utility(int state, int player);

    static bool finished(int state);

    static CustomArray next_states(int state, int player);

    static CustomArray empty(int state);

    static bool final_msg(int state);

private:
    static int calcArrSize(const int *xArr, const int *oArr);
};


#endif //TIC_TAC_TOE_TICTACTOE_H
