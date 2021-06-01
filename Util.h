//
// Created by Marvin on 30.05.2021.
//

#ifndef TIC_TAC_TOE_UTIL_H
#define TIC_TAC_TOE_UTIL_H


class Util {
public:
    constexpr static const int Players[2] = {0, 1};

    static int set_bits(const int *bits, const size_t size) {
        int result = 0;
        for (int i = 0; i < size; i++) {
            result |= 1 << bits[i];
        }
        return result;
    }

    static int set_bit(int power) {
        return 1 << power;
    }

    static std::string to_board(int state) {
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
};


#endif //TIC_TAC_TOE_UTIL_H
