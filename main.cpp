#include <iostream>
#include <cmath>
#include <string>

int players[2]{0, 1};
int start = 0;

int set_bits(const int bits[], const size_t size) {
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

int main() {
    int bits[]{0, 2, 3, 5, 7, 9 + 1, 9 + 4, 9 + 6};
    int state = set_bits(bits, 8);
    std::cout << to_board(state);
    return 0;
}

