//
// Created by Marvin on 30.05.2021.
//

#include "TicTacToe.h"
#include "Util.h"

int TicTacToe::calcArrSize(const int *xArr, const int *oArr) {
    int result = 0;
    for (int i = 0; i < 9; i++) {
        if (xArr[i] == 1 || oArr[i] == 1) {
            result++;
        }
    }
    return result;
}

CustomArray TicTacToe::empty(int state) {
    int *xArr{new int[9]{}};
    int resultArrSize;
    const int MAX_SUM = 9;
    int *oArr{new int[9]{}};
    for (int i = 0; i < 9; i++) {
        if ((state & (1 << i)) != 0) {
            // i-th bit is set with X
            xArr[i] = 1;
        }
        if ((state & (1 << (9 + i))) != 0) {
            // (9+i)-th bit is set with O
            oArr[i] = 1;
        }
    }
    resultArrSize = MAX_SUM - calcArrSize(xArr, oArr);
    static int *resultArr{new int[resultArrSize]{}};
    int resultIndex = 0;
    for (int i = 0; i < 9; i++) {
        if (xArr[i] == 0 && oArr[i] == 0) {
            // cell is empty
            resultArr[resultIndex++] = i;
        }
    }
    return CustomArray(resultArr, resultArrSize);
}

CustomArray TicTacToe::next_states(int state, int player) {
    CustomArray emptyCells = empty(state);
    static int *resultArr{new int[emptyCells.size]{}};
    for (int i = 0; i < emptyCells.size; i++) {
        int next_state = state | Util::set_bit(player * 9 + emptyCells.arr[i]);
        resultArr[i] = next_state;
    }
    return CustomArray(resultArr, emptyCells.size);
}

int TicTacToe::utility(int state, int player) {
    for (int i = 0; i < 8; i++) {
        int mask = Util::all_lines()[i];
        if ((state & mask) == mask) {
            return 1 - 2 * player; // player 'X' has won
        }
        if (((state >> 9) & mask) == mask) {
            return -1 + 2 * player; // player 'O' has won
        }
    }
    if (((state & 511) | (state >> 9)) != 511) {
        return 2; // the board is not yet filled
    }
    return 0; // it's a draw
}

bool TicTacToe::finished(int state) {
    return utility(state, 0) != 2;
}


bool TicTacToe::final_msg(int state) {
    if (finished(state)) {
        if (utility(state, 1) == 1) {
            std::cout << "You have won!\n";
        } else if (utility(state, 1) == -1) {
            std::cout << "You have lost!\n";
        } else {
            std::cout << "It's a draw!\n";
        }
        return true;
    }
    return false;
}
