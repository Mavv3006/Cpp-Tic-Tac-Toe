//
// Created by Marvin on 30.05.2021.
//

#ifndef TIC_TAC_TOE_UTIL_H
#define TIC_TAC_TOE_UTIL_H

#include <iostream>
#include "vector"
#include "array"

class Util {
public:
    static constexpr int Players[2] = {0, 1};

    /**
     * @param bits an array with a list of numbers that specify bit positions in an integer
     * @param size the size of the array, i.e. the number of positions in the integer to set
     * @return an integer such that the bits specified in bits are set. Counting starts with 0.
     */
    template<long unsigned int size>
    static int set_bits(const std::array<int, size> &bits) {
        int result = 0;
        for (int i = 0; i < size; i++) {
            result |= 1 << bits[i];
        }
        return result;
    }

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
                set_bits(std::array<int, 3>{0, 1, 2}), // 1st row
                set_bits(std::array<int, 3>{3, 4, 5}), // 2nd row
                set_bits(std::array<int, 3>{6, 7, 8}), // 3rd row
                set_bits(std::array<int, 3>{0, 3, 6}), // 1st column
                set_bits(std::array<int, 3>{1, 4, 7}), // 2nd column
                set_bits(std::array<int, 3>{2, 5, 8}), // 3rd column
                set_bits(std::array<int, 3>{0, 4, 8}), // falling diagonal
                set_bits(std::array<int, 3>{2, 4, 6}), // rising diagonal
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

    static void printf_array(std::vector<int> array) {
        printf("[ ");
        for (int i = 0; i < array.size(); i++) {
            printf("%d", array.at(i));
            if (array.size() - i > 1) {
                printf(", ");
            }
        }
        printf(" ]\n");
        fflush(stdout);
    }
};


#endif //TIC_TAC_TOE_UTIL_H
