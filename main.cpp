#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Util.h"

/**
 * The function get_move asks the user to input a move
 * in the format r,c where r is the row and the
 * c is the column where the symbol is to be placed.
 * */
int get_move(int state) {
    int row, col;
    std::string input;
    std::vector<std::string> result;
    while (true) {
        std::cout << "move: ";
        std::cin >> input;
        std::stringstream ss(input);
        while (ss.good()) {
            std::string substr;
            std::getline(ss, substr, ',');
            result.push_back(substr);
        }
        try {
            if (result.size() != 2) throw std::invalid_argument("");

            row = std::stoi(result[0]);
            col = std::stoi(result[1]);
            int mask = Util::set_bit(9 + row * 3 + col);
            if ((state & mask) == 0) {
                return state | mask;
            } else {
                throw std::invalid_argument("");
            }
        }
        catch (std::invalid_argument &e) {
            std::cout << "\nIllegal input. Please try again\n";
        }
    }
}



int main() {
    int move = get_move(7);
    std::cout << "move: " << move;

    return 0;
}

