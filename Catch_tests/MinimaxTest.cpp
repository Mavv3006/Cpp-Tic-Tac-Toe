//
// Created by marvd on 02.06.2021.
//

#include "catch.hpp"
#include "Minimax.h"

TEST_CASE("value function", "[Minimax Test]") {
    int state, value;
    SECTION("player can force a win") {
        state = Util::set_bits(new int[]{0, 1}, 2);

        value = Minimax::value(state, 0);

        CHECK(value == 1);
    }SECTION("player can force a draw") {
        const int *bits = new int[]{2, 5, 6, 7, 1 + 9, 3 + 9, 4 + 9, 8 + 9};
        state = Util::set_bits(bits, 8);

        value = Minimax::value(state, 0);

        CHECK(value == 0);
    }SECTION("opponent of player can force a win") {
        const int *bits = new int[]{0, 1, 4};
        state = Util::set_bits(bits, 3);

        value = Minimax::value(state, 1);

        CHECK(value == -1);
    }
}

TEST_CASE("best_move function", "[Minimax Test]") {
    int state;
    const int *bits = new int[]{0, 1, 4};
    state = Util::set_bits(bits, 3);
    BestMove bestMove = Minimax::best_move(state, 0);
    CHECK(bestMove.val == 1);
    bool secoundBitSet = (bestMove.state & (1 << 2)) == (1 << 2);
    bool seventhBitSet = (bestMove.state & (1 << 7)) == (1 << 7);
    bool assertion = secoundBitSet || seventhBitSet;
    CHECK(assertion);
}