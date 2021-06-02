//
// Created by Marvin on 30.05.2021.
//

#ifndef TIC_TAC_TOE_UTIL_H
#define TIC_TAC_TOE_UTIL_H


#include "CustomArray.h"

class Util {
public:
    constexpr static const int Players[2] = {0, 1};

    /**
     *
     * @param bits an array with a list of numbers that specify bit positions in an integer
     * @param size the size of the array, i.e. the number of positions in the integer to set
     * @return an integer such that the bits specified in bits are set. Counting starts with 0.
     */
    static int set_bits(const int *bits, const size_t size) {
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
    static int *all_lines() {
        return new int[]{
                set_bits(new int[3]{0, 1, 2}, 3), // 1st row
                set_bits(new int[3]{3, 4, 5}, 3), // 2nd row
                set_bits(new int[3]{6, 7, 8}, 3), // 3rd row
                set_bits(new int[3]{0, 3, 6}, 3), // 1st column
                set_bits(new int[3]{1, 4, 7}, 3), // 2nd column
                set_bits(new int[3]{2, 5, 8}, 3), // 3rd column
                set_bits(new int[3]{0, 4, 8}, 3), // falling diagonal
                set_bits(new int[3]{2, 4, 6}, 3), // rising diagonal
        };
    }

    static void print_array(const int *arr, const size_t size) {
        std::cout << "[ ";
        for (int i = 0; i < size; i++) {
            std::cout << arr[i];
            if (size - i > 1) {
                std::cout << ", ";
            }
        }
        std::cout << " ]\n";
    }

    static void print_array(CustomArray array) {
        std::cout << "[ ";
        for (int i = 0; i < array.getSize(); i++) {
            std::cout << array.getAt(i);
            if (array.getSize() - i > 1) {
                std::cout << ", ";
            }
        }
        std::cout << " ]\n";
    }

    static void printf_array(CustomArray array) {
        printf("[ ");
        for (int i = 0; i < array.getSize(); i++) {
            printf("%d", array.getAt(i));
            if (array.getSize() - i > 1) {
                printf(", ");
            }
        }
        printf(" ]\n");
        fflush(stdout);
    }

    static void printf_array(const int *arr, const size_t size) {
        printf("[ ");
        for (int i = 0; i < size; i++) {
            printf("%d", arr[i]);
            if (size - i > 1) {
                printf(", ");
            }
        }
        printf(" ]\n");
        fflush(stdout);
    }
};


#endif //TIC_TAC_TOE_UTIL_H
