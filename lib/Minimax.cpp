//
// Created by marvd on 01.06.2021.
//

#include "Minimax.h"

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
        int nextValue = -value(nextState, player ^ 1);
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
    std::vector<int> nextStates = TicTacToe::next_states(state, player);
    int maxValue = -2;
    int val, cached_val;
    for (int nextState : nextStates) {
        int idx = (nextState << 1) | player;

        cached_val = (arr[idx >> 4] >> ((idx & 0b1111) << 1)) & 0b11;

        if (cached_val) {
            // nehme Wert aus Array
            // val = arr[idx >> 4];
            val = (cached_val ^= 0b10);
            if (cached_val == 0b11)
                val = -1;
        } else {
            // berechne neu
            val = -value(nextState, player ^ 1);
            cached_val = (val & 0b11) ^ 0b10;
            arr[idx >> 4] = arr[idx >> 4] | (cached_val << ((idx & 0b1111) << 1));
        }
        if (val == 1) return 1;
        if (val > maxValue) maxValue = val;
    }
    return maxValue;
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

int Minimax::arr[1 << 15] = {0};
