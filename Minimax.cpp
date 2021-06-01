//
// Created by marvd on 01.06.2021.
//

#include "Minimax.h"

BestMove Minimax::best_move(int state, int player) {
    CustomArray nextStates = TicTacToe::next_states(state, player);
    Util::print_array(nextStates);
    int bestValue = value(state, player);
    int bestMovesSize = 0;
    int *bestMoves{new int[bestMovesSize]{}};
    for (int i = 0; i < nextStates.size; i++) {
        if (-value(nextStates.arr[i], other(player)) == bestValue) {
            bestMoves[bestMovesSize++] = nextStates.arr[i];
        }
    }
    Util::print_array(bestMoves, bestMovesSize);
    int returnMove = bestMoves[random(0, bestMovesSize)];
    const BestMove bestMove = BestMove(bestValue, returnMove);
    return bestMove;
}

int Minimax::value(int state, int player) {
    if (TicTacToe::finished(state)) {
        return TicTacToe::utility(state, player);
    }
    int o = other(player);
    CustomArray nextStates = TicTacToe::next_states(state, player);
    int maxValue = -2; // TODO: tidy up
    for (int i = 0; i < nextStates.size; i++) {
        int val = -value(nextStates.arr[i], o);
        if (val > maxValue) maxValue = val;
    }
    return maxValue;
}

int Minimax::other(int p) {
    if (Util::Players[0] == p) {
        return Util::Players[1];
    }
    return Util::Players[0];
}

int Minimax::random(int lowerBound, int upperBound) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution distribution(lowerBound, upperBound);
    return distribution(gen);
}

BestMove::BestMove(int val, int state) {
    this->state = state;
    this->val = val;
}
