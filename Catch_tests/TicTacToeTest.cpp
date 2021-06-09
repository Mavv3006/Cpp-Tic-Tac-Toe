//
// Created by marvd on 01.06.2021.
//

#define CATCH_CONFIG_MAIN

#include <Util.h>
#include "catch.hpp"
#include "TicTacToe.h"
#include "states.h"

TEST_CASE("Value of start") {
    int start = TicTacToe::start;

    CHECK(start == 0);
}

TEST_CASE("empty function") {
    int state, checking_state[8];
    for (int i = 0; i < 9; i++) {
        state = Util::set_bit(i);
        std::vector<int> emptyCells = TicTacToe::empty(state);

        // set checking state
        int arrayIndex = 0;
        for (int boardIndex = 0; boardIndex < 9; boardIndex++) {
            if (boardIndex == i) {
                continue;
            }
            checking_state[arrayIndex] = boardIndex;
            arrayIndex++;
        }

        CHECK(emptyCells.size() == 8);

        // check content of emptyCells array
        for (int j = 0; j < 8; j++) {
            CHECK(checking_state[j] == emptyCells.at(j));
        }
    }
}

TEST_CASE("next_states function") {
    int state = 0, checking_state[9];
    // set checking state
    for (int i = 0; i < 9; i++) {
        checking_state[i] = Util::set_bit(i);
    }

    std::vector<int> emptyCells = TicTacToe::next_states(state, 0);

    CHECK(emptyCells.size() == 9);
    // check content of emptyCells array
    for (int j = 0; j < 8; j++) {
        CHECK(checking_state[j] == emptyCells.at(j));
    }
}

//TEST_CASE("utility function") {
//    SECTION("Player X will win") {
//        CHECK(TicTacToe::utility(States::winningState(), 0) == 1);
//    }SECTION("Player O will win") {
//        CHECK(TicTacToe::utility(States::losingState(), 0) == -1);
//    }SECTION("It's a draw") {
//        CHECK(TicTacToe::utility(States::drawingState(), 0) == 0);
//    } SECTION("Not yet decided") {
//        CHECK(TicTacToe::utility(0, 0) == 2);
//    }
//}

//TEST_CASE("finished function") {
//    SECTION("Player X will win") {
//        CHECK(TicTacToe::finished(States::winningState()) == true);
//    }SECTION("Player O will win") {
//        CHECK(TicTacToe::finished(States::losingState()) == true);
//    }SECTION("It's a draw") {
//        CHECK(TicTacToe::finished(States::drawingState()) == true);
//    }SECTION("Not yet decided") {
//        CHECK(TicTacToe::finished(0) == false);
//    }
//}

//TEST_CASE("final_msg function") {
//    SECTION("Player X will win") {
//        CHECK(TicTacToe::final_msg(States::losingState()) == true);
//    }SECTION("Player O will win") {
//        CHECK(TicTacToe::final_msg(States::winningState()) == true);
//    }SECTION("It's a draw") {
//        CHECK(TicTacToe::final_msg(States::drawingState()) == true);
//    }SECTION("Not yet decided") {
//        CHECK(TicTacToe::final_msg(0) == false);
//    }
//}

TEST_CASE("same memory address for next_states result") {
    const int state = 0, player = 0;
    std::vector<int> ns1 = TicTacToe::next_states(state, player);
    std::vector<int> ns2 = TicTacToe::next_states(1, player);
    REQUIRE(ns1.at(0) != ns2.at(0));
}

TEST_CASE("markedCellsCount function") {
    int markedCells = TicTacToe::markedCellsCount(0b110010110111);
    CHECK(markedCells == 8);
}
