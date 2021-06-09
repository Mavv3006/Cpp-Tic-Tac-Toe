//
// Created by Marvin on 30.05.2021.
//

#ifndef TIC_TAC_TOE_UTIL_H
#define TIC_TAC_TOE_UTIL_H

#include <iostream>
#include "vector"
#include "array"
#include "bitset"

class Util {
public:
    /**
     * @param power the bit to set
     * @return a number that has exactly the n-th bit set.
     */
    static int set_bit(int power) {
        return 1 << power;
    }

    /**
     * The function converts the current state of the game into a string that represents the
     * board corresponding to the state.
     *
     * @param state the current state of the game
     */
    static void to_board(int state) {
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
        std::cout << result;
    }

    /**
     * @return a list of eight bit masks. These masks can be used to test whether there are
     * three identical masks in a row, column or diagonal.
     */
    static std::array<int, 8> winning_states() {
        return std::array<int, 8>{
                0b111, 0b111000, 0b111000000, 0b1001001,
                0b10010010, 0b100100100, 0b100010001, 0b1010100
        };
    }

    static void print_array(std::vector<int> array) {
        std::cout << "[ ";
        for (int i = 0; i < array.size(); i++) {
            std::cout << array.at(i);
            if (array.size() - i > 1) {
                std::cout << ", ";
            }
        }
        std::cout << " ]\n";
    }

    static void print_array(const int *arr, int size) {
        int counter = 0;
        std::cout << "[ ";
        for (int i = 0; i < size; i++) {
            int value = arr[i];
            if (!value)continue;
            counter++;
            std::bitset<32> val = value;
            std::cout << val;
            if (size - i > 1) {
                std::cout << ", ";
            }
        }
        std::cout << " ]\n\ncounter: " << counter << "\n";
    }
};


#endif //TIC_TAC_TOE_UTIL_H
