#include <iostream>
#include <cmath>
#include <string>
#include "CustomArray.h"

int calcArrSize(const int *xArr, const int *oArr);

void printArray(const int *arr, size_t size);

int set_bits(const int *bits, const size_t size) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result |= 1 << bits[i];
    }
    return result;
}

int set_bit(int power) {
    return 1 << power;
}

std::string to_board(int state) {
    std::string result = "+-+-+-+\n";
    for (int cell = 0; cell < 9; cell++) {
        if ((state & set_bit(cell)) != 0) {
            result += "|X";
        } else if ((state & set_bit(cell + 9)) != 0) {
            result += "|O";
        } else {
            result += "| ";
        }
        if ((cell + 1) % 3 == 0) {
            result += "|\n+-+-+-+\n";
        }
    }
    return result;
}

/*
 * Given a `state` that is represented as a number, the function `empty(state)`
 * returns the set of indexes of those cells such that neither player `X` nor
 * player `O` has placed a mark in the cell.  Note that there are 9 cells on
 * the board.  Each of these cells can hold either an `'X'` or an `'O'`.
 * If the $i^\textrm{th}$ cell is marked with a `'X'`, then the $i^\textrm{th}$
 * bit of `state` is set.  If instead the $i^\textrm{th}$ cell is marked with
 * an `'O'`, then the $(9+i)^\textrm{th}$ bit of `state` is set.  If the
 * $i^\textrm{th}$ cell is not yet marked, then both the $i^\textrm{th}$ bit
 * and the $(9+i)^\textrm{th}$ are $0$.
 * */
CustomArray empty(int state) {
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
//    std::cout << "free cells count: " << resultArrSize << std::endl;
    static int *resultArr{new int[resultArrSize]{}};
    int resultIndex = 0;
    for (int i = 0; i < 9; i++) {
        if (xArr[i] == 0 && oArr[i] == 0) {
            // cell is empty
            resultArr[resultIndex++] = i;
        }
    }
//    printArray(resultArr, resultArrSize);
    return CustomArray(resultArr, resultArrSize);
}

int calcArrSize(const int *xArr, const int *oArr) {
    int result = 0;
    for (int i = 0; i < 9; i++) {
        if (xArr[i] == 1 || oArr[i] == 1) {
            result++;
        }
    }
//    std::cout << "result Arr size: " << result << std::endl;
    return result;
}

void printArray(const int *arr, size_t size) {
    std::cout << "[ ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
        if (size - i != 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ]\n";
}

/*
 * Given a `state` and the `player` who is next to move, the function
 * `next_states(state, player)` computes the set of states that can be
 * reached from `state`. Note that player `X` is encoded as the number
 * $0$, while player `O` is encoded as the number $1$.
 * */
CustomArray next_states(int state, int player) {
    CustomArray emptyCells = empty(state);
    static int *resultArr{new int[emptyCells.size]{}};
    for (int i = 0; i < emptyCells.size; i++) {
        int next_state = state | set_bit(player * 9 + emptyCells.arr[i]);
        resultArr[i] = next_state;
    }
    return CustomArray(resultArr, emptyCells.size);
}


int main() {
    int state = set_bits(new int[6]{2, 3, 5, 9 + 1, 9 + 4, 9 + 6}, 6);
    std::cout << "state:\n" << to_board(state) << "\nnext states:\n";
    CustomArray nextStates = next_states(state, 0);
    for (int i = 0; i < nextStates.size; i++) {
        std::cout << to_board(nextStates.arr[i]) << std::endl;
    }

    return 0;
}

