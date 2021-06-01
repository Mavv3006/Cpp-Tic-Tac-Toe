#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "lib/Util.h"
#include "lib/TicTacToe.h"
#include "lib/Minimax.h"

/**
 * The function get_move asks the user to input a move
 * in the format r,c where r is the row and the
 * c is the column where the symbol is to be placed.
 * @param state the current state of the game
 */
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

void play_game() {
    int state = TicTacToe::Start;
    while (true) {
        int firstPlayer = Util::Players[0];
        BestMove bestMove = Minimax::best_move(state, firstPlayer);
        state = bestMove.state;
        Util::to_board(state);
        return;
//        std::cout << "for me, the game has the value " << bestMove.val << ".\n";
//        if (TicTacToe::finished(state)) {
//            TicTacToe::final_msg(state);
//            return;
//        }
//        std::cout << "\n\n";
//        state = get_move(state);
//        Util::to_board(state);
//        if (TicTacToe::finished(state)) {
//            TicTacToe::final_msg(state);
//            return;
//        }
    }
}

int main() {
    play_game();

    return 0;
}

