//
// Created by marvd on 01.06.2021.
//

#include "Minimax.h"

BestMove Minimax::best_move(int state, int player) {
    int bestValue = value(state, player);
    std::vector<int> nextStates = TicTacToe::next_states(state, player);
    Util::printf_array(nextStates);
    int bestMovesSize = 0;
    int *bestMoves{new int[nextStates.size()]{}};
    for (int nextState : nextStates) {
        int nextValue = -value(nextState, other(player));
        if (nextValue == bestValue) {
            bestMoves[bestMovesSize] = nextState;
            bestMovesSize++;
        }
    }
    Util::printf_array(bestMoves, bestMovesSize);
    int returnMove = bestMoves[random(0, bestMovesSize)];
    const BestMove bestMove = BestMove(bestValue, returnMove);
    return bestMove;
}

int Minimax::value(int state, int player) {
    if (TicTacToe::finished(state)) {
        return TicTacToe::utility(state, player);
    }
    int o = other(player);
    std::vector<int> nextStates = TicTacToe::next_states(state, player);
    int maxValue = -2; // TODO: tidy up
    for (int nextState : nextStates) {
        int val = -value(nextState, o);
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
