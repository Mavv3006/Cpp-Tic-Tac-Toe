//
// Created by marvd on 01.06.2021.
//

#define CATCH_CONFIG_MAIN

#include <Util.h>
#include "catch.hpp"
#include "TicTacToe.h"

TEST_CASE("Value of start") {
    int start = TicTacToe::start;

    CHECK(start == 0);
}

TEST_CASE("empty function") {
    int state, checking_state[8];
    for (int i = 0; i < 9; i++) {
        state = Util::set_bit(i);
        CustomArray emptyCells = TicTacToe::empty(state);

        // set checking state
        int arrayIndex = 0;
        for (int boardIndex = 0; boardIndex < 9; boardIndex++) {
            if (boardIndex == i) {
                continue;
            }
            checking_state[arrayIndex] = boardIndex;
            arrayIndex++;
        }

        CHECK(emptyCells.getSize() == 8);

        // check content of emptyCells array
        for (int j = 0; j < 8; j++) {
            CHECK(checking_state[j] == emptyCells.getAt(j));
        }
    }
}

TEST_CASE("next_states function") {
    int state = 0, checking_state[9];
    // set checking state
    for (int i = 0; i < 9; i++) {
        checking_state[i] = Util::set_bit(i);
    }

    CustomArray emptyCells = TicTacToe::next_states(state, 0);

    CHECK(emptyCells.getSize() == 9);
    // check content of emptyCells array
    for (int j = 0; j < 8; j++) {
        CHECK(checking_state[j] == emptyCells.getAt(j));
    }
}

TEST_CASE("utility function") {
    int state;
    const int player = 0;
    SECTION("Player X will win") {
        state = Util::set_bits(new int[3]{0, 1, 2}, 3);
        CHECK(TicTacToe::utility(state, player) == 1);
    }SECTION("Player O will win") {
        state = Util::set_bits(new int[3]{9 + 0, 9 + 1, 9 + 2}, 3);
        CHECK(TicTacToe::utility(state, player) == -1);
    }SECTION("It's a draw") {
        const int *bits = new int[9]{0, 2, 5, 6, 7, 1 + 9, 3 + 9, 4 + 9, 8 + 9};
        state = Util::set_bits(bits, 9);
        CHECK(TicTacToe::utility(state, player) == 0);
    }SECTION("Not yet decided") {
        state = 0;
        CHECK(TicTacToe::utility(state, player) == 2);
    }
}

TEST_CASE("finished function") {
    int state;
    SECTION("Player X will win") {
        state = Util::set_bits(new int[3]{0, 1, 2}, 3);
        CHECK(TicTacToe::finished(state) == true);
    }SECTION("Player O will win") {
        state = Util::set_bits(new int[3]{9 + 0, 9 + 1, 9 + 2}, 3);
        CHECK(TicTacToe::finished(state) == true);
    }SECTION("It's a draw") {
        const int *bits = new int[9]{0, 2, 5, 6, 7, 1 + 9, 3 + 9, 4 + 9, 8 + 9};
        state = Util::set_bits(bits, 9);
        CHECK(TicTacToe::finished(state) == true);
    }SECTION("Not yet decided") {
        state = 0;
        CHECK(TicTacToe::finished(state) == false);
    }
}

TEST_CASE("final_msg function") {
    int state;
    SECTION("Player X will win") {
        state = Util::set_bits(new int[3]{0, 1, 2}, 3);
        CHECK(TicTacToe::final_msg(state) == true);
    }SECTION("Player O will win") {
        state = Util::set_bits(new int[3]{9 + 0, 9 + 1, 9 + 2}, 3);
        CHECK(TicTacToe::final_msg(state) == true);
    }SECTION("It's a draw") {
        const int *bits = new int[9]{0, 2, 5, 6, 7, 1 + 9, 3 + 9, 4 + 9, 8 + 9};
        state = Util::set_bits(bits, 9);
        CHECK(TicTacToe::final_msg(state) == true);
    }SECTION("Not yet decided") {
        state = 0;
        CHECK(TicTacToe::final_msg(state) == false);
    }
}

TEST_CASE("same memory address for next_states result") {
    const int state = 0, player = 0;
    CustomArray ns1 = TicTacToe::next_states(state, player);
    for (int i = 0; i < ns1.getSize(); i++) {
        printf_s("ns1[%d]=%d, ", i, ns1.getAt(i));
    }
    printf_s("\n\n\n");
    CustomArray ns2 = TicTacToe::next_states(1, player);

    for (int i = 0; i < ns1.getSize(); i++) {
        printf_s("ns1[%d]=%d, ns2[%d]=%d\n", i, ns1.getAt(i), i, ns2.getAt(i));
    }
    fflush(stdout);
    REQUIRE(ns1.getAt(0) != ns2.getAt(0));
}
