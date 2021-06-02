//
// Created by marvd on 01.06.2021.
//

#include "Minimax.h"
#include "memoize.h"

BestMove Minimax::best_move(int state, int player) {
    int bestValue = value(state, player);
    std::vector<int> bestMoves = calc_best_moves(bestValue, state, player);
    int returnMove = bestMoves[random(bestMoves.size() - 1)];
    return BestMove(bestValue, returnMove);
}

std::vector<int> Minimax::calc_best_moves(int bestValue, int state, int player) {
    std::vector<int> nextStates = TicTacToe::next_states(state, player);
    std::vector<int> bestMoves;
    bestMoves.reserve(nextStates.size());
    for (int nextState : nextStates) {
        int nextValue = -value(nextState, Minimax::other(player));
        if (nextValue == bestValue) {
            bestMoves.push_back(nextState);
        }
    }
    return bestMoves;
}

int Minimax::value(int state, int player) {
    if (TicTacToe::finished(state)) {
        return TicTacToe::utility(state, player);
    }
    int o = other(player);
    std::vector<int> nextStates = TicTacToe::next_states(state, player);
    int maxValue = -2; // TODO: tidy up
    for (int nextState : nextStates) {
        int val = -STATIC_MEMOIZER(value)(nextState, o);
        if (val == 1) return 1;
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

int Minimax::random(unsigned int upperBound) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution distribution(0, (int) upperBound);
    return distribution(gen);
}

BestMove::BestMove(int val, int state) {
    this->state = state;
    this->val = val;
}
