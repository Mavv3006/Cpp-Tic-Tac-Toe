//
// Created by marvd on 01.06.2021.
//

#ifndef TIC_TAC_TOE_MINIMAX_H
#define TIC_TAC_TOE_MINIMAX_H

#include <random>
#include "TicTacToe.h"
#include "Util.h"


struct BestMove {
    int val;
    int state;

    BestMove(int val, int state);
};

class Minimax {
private:
    static int random(unsigned int upperBound);


public:
    static int arr[32768];
    static std::vector<int> calc_best_moves(int bestValue, int state, int player);

/**
 *
 * @param state the current state of the game
 * @param player a player of the game
 * @return returns the value that the given state has for player if both players play
 * their best game. This values is an element from the set {-1, 0, 1}.
 * - If player can force a win, then the return value is 1.
 * - If player can at best force a draw, then the return value is 0.
 * - If the opponent of player can force a win for herself, then the return value is -1.
 */
    static int value(int state, int player);


/**
 *
 * @param state the current state of the game
 * @param player a player of the game
 */
    static BestMove best_move(int state, int player);
};


#endif //TIC_TAC_TOE_MINIMAX_H
