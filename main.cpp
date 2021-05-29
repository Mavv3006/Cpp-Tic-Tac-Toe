#include <iostream>
#include <cmath>
#include <string>
#include "EmptyArray.h"

int players[2]{0, 1};
int start = 0;

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

EmptyArray empty(int state) {
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
    std::cout << "free cells count: " << resultArrSize << std::endl;
    static int *resultArr{new int[resultArrSize]{}};
    int resultIndex = 0;
    for (int i = 0; i < 9; i++) {
        if (xArr[i] == 0 && oArr[i] == 0) {
            // cell is empty
            resultArr[resultIndex++] = i;
        }
    }
    printArray(resultArr, resultArrSize);
    return EmptyArray(resultArr, resultArrSize);
}

int calcArrSize(const int *xArr, const int *oArr) {
    int result = 0;
    for (int i = 0; i < 9; i++) {
        if (xArr[i] == 1 || oArr[i] == 1) {
            result++;
        }
    }
    std::cout << "result Arr size: " << result << std::endl;
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
    std::cout << " ]";
}

int main() {
    int state = set_bits(new int[6]{2, 3, 5, 9 + 1, 9 + 4, 9 + 8}, 6);
    std::cout << to_board(state) << std::endl;
    EmptyArray emptyArray = empty(state);
    printArray(emptyArray.arr, emptyArray.size);

    return 0;
}

