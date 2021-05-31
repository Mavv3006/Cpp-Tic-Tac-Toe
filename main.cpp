#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Util.h"
#include "TicTacToe.h"
#include <random>

int Players[]{0, 1};
int num_value_calls = 0;

struct BestMove {
    int val;
    int state;

    BestMove(int val, int state) {
        this->state = state;
        this->val = val;
    }
};

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

/**
 * Given a player p, the function other(p) computes the opponent of p. This assumes
 * that there are only two players and the set of all players is stored in the global
 * variable Players.
 */
int other(int p) {
    if (Players[0] == p) {
        return Players[1];
    }
    return Players[0];
}

/**
 *
 * @param state is the current state of the game
 * @param player is a player
 * @return returns the value that the given state has for player if both players play
 * their best game. This values is an element from the set {-1, 0, 1}.
 * - If player can force a win, then the return value is 1.
 * - If player can at best force a draw, then the return value is 0.
 * - If the opponent of player can force a win for herself, then the return value is -1.
 */
int value(int state, int player) {
    num_value_calls++;
    if (TicTacToe::finished(state)) {
        return TicTacToe::utility(state, player);
    }
    int o = other(player);
    CustomArray nextStates = TicTacToe::next_states(state, player);
    int maxValue;
    for (int i = 0; i < nextStates.size; i++) {
        int val = -value(nextStates.arr[i], o);
        if (val > maxValue) maxValue = val;
    }
    return maxValue;
}

int random(int lowerBound, int upperBound) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution distribution(lowerBound, upperBound);
    return distribution(gen);
}

/**
 *
 * @param state is the current state of the game
 * @param player is a player
 */
BestMove best_move(int state, int player) {
    CustomArray nextStates = TicTacToe::next_states(state, player);
    int bestValue = value(state, player);
    int bestMovesSize = 0;
    int *bestMoves{new int[bestMovesSize]{}};
    for (int i = 0; i < nextStates.size; i++) {
        if (-value(nextStates.arr[i], other(player)) == bestValue) {
            bestMoves[bestMovesSize++] = nextStates.arr[i];
        }
    }
    // TODO: return array with two values: bestValue and bestState
    return BestMove(bestValue, bestMoves[random(0, bestMovesSize)]);
}

int main() {

    return 0;
}

