#include "lib/Util.h"
#include "lib/Minimax.h"

#define BENCHMARKING 1
#if BENCHMARKING

#include <Timer.h>
#include "fstream"
#include "iostream"
#include "memoize.h"

void clearFile(std::string &fileName) {
    std::ofstream file;
    file.open(fileName, std::ofstream::out | std::ofstream::trunc);
    file.close();
}

void benchmark(std::string &fileName) {
    const int starting_state = 0, starting_player = 0;
    for (int i = 0; i < 50; i++) {
        cache<int, int, int>->clear();
        {
            Timer timer{fileName};
            Minimax::value(starting_state, starting_player);
        }
    }
}

#else
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "lib/TicTacToe.h"

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
        std::cout << "enter your move (row, column): ";
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
    int state = TicTacToe::start;
    std::cout << "Hint: we don't check whether the cell is marked yet or not" << std::endl;
    while (true) {
        int firstPlayer = Util::Players[0];
        BestMove bestMove = Minimax::best_move(state, firstPlayer);
        state = bestMove.state;
        Util::to_board(state);
        std::cout << "for me, the game has the value " << bestMove.val << ".\n";
        if (TicTacToe::finished(state)) {
            TicTacToe::final_msg(state);
            return;
        }
        std::cout << "\n";
        state = get_move(state);
        Util::to_board(state);
        if (TicTacToe::finished(state)) {
            TicTacToe::final_msg(state);
            return;
        }
    }
}
#endif

int main() {
#if BENCHMARKING
    std::string fileName = "performance.txt";
    clearFile(fileName);
    benchmark(fileName);
#else
    play_game();
#endif

    return 0;
}

