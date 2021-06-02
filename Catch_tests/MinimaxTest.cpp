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
    }SECTION("state 0, player 0") {
        value = Minimax::value(0, 0);
        CHECK(value == 0);
    }
}

TEST_CASE("calc_best_moves function: state 0, player 0", "[Minimax Test]") {
    const int state = 0, player = 0;
    int value = Minimax::value(state, player);

    std::vector<int> bestMove = Minimax::calc_best_moves(value, state, player);
    Util::print_array(bestMove);

    CHECK(bestMove.size() == 9);
    CHECK(bestMove.at(0) == 1);
    CHECK(bestMove.at(1) == 2);
    CHECK(bestMove.at(2) == 4);
    CHECK(bestMove.at(3) == 8);
    CHECK(bestMove.at(4) == 16);
    CHECK(bestMove.at(5) == 32);
    CHECK(bestMove.at(6) == 64);
    CHECK(bestMove.at(7) == 128);
    CHECK(bestMove.at(8) == 256);
}

TEST_CASE("calc_best_moves function: state 1, player 0", "[Minimax Test]") {
    const int state = 1, player = 0;
    int value = Minimax::value(state, player);

    std::vector<int> bestMove = Minimax::calc_best_moves(value, state, player);
    Util::print_array(bestMove);

    CHECK(bestMove.size() == 8);
    CHECK(bestMove.at(0) == 3);
    CHECK(bestMove.at(1) == 5);
    CHECK(bestMove.at(2) == 9);
    CHECK(bestMove.at(3) == 17);
    CHECK(bestMove.at(4) == 33);
    CHECK(bestMove.at(5) == 65);
    CHECK(bestMove.at(6) == 129);
    CHECK(bestMove.at(7) == 257);
}

TEST_CASE("calc_best_moves function: state 33, player 0", "[Minimax Test]") {
    const int state = 33, player = 0;
    int value = Minimax::value(state, player);

    std::vector<int> bestMove = Minimax::calc_best_moves(value, state, player);
    Util::print_array(bestMove);

    CHECK(bestMove.size() == 7);
    CHECK(bestMove.at(0) == 35);
    CHECK(bestMove.at(1) == 37);
    CHECK(bestMove.at(2) == 41);
    CHECK(bestMove.at(3) == 49);
    CHECK(bestMove.at(4) == 97);
    CHECK(bestMove.at(5) == 161);
    CHECK(bestMove.at(6) == 289);
}

TEST_CASE("calc_best_moves function: state 33, player 1", "[Minimax Test]") {
    const int state = 33, player = 1;
    int value = Minimax::value(state, player);

    std::vector<int> bestMove = Minimax::calc_best_moves(value, state, player);
    Util::print_array(bestMove);

    CHECK(bestMove.size() == 7);
    CHECK(bestMove.at(0) == 1057);
    CHECK(bestMove.at(1) == 2081);
    CHECK(bestMove.at(2) == 4129);
    CHECK(bestMove.at(3) == 8225);
    CHECK(bestMove.at(4) == 32801);
    CHECK(bestMove.at(5) == 65569);
    CHECK(bestMove.at(6) == 131105);
}

static void test_best_move_function(int state, int player) {
    int value = Minimax::value(state, player);
    std::vector<int> next_states = Minimax::calc_best_moves(value, state, player);

    BestMove bestMove = Minimax::best_move(state, player);

    auto iterator = std::find(next_states.begin(), next_states.end(), bestMove.state);
    CHECK(iterator != next_states.end());
    CHECK(bestMove.val == value);
}

TEST_CASE("best_move function", "[Minimax Test]")
{
    SECTION("state: 0, player: 0") {
        test_best_move_function(0, 0);
    }SECTION("state: 33, player: 1") {
        test_best_move_function(33, 1);
    }SECTION("state: 1600, player: 0") {
        test_best_move_function(1600, 0);
    }
}
