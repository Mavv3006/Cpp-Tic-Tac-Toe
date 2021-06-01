//
// Created by marvd on 01.06.2021.
//

#define CATCH_CONFIG_MAIN

#include "catch.hpp"
#include "TicTacToe.h"

TEST_CASE("Value of start") {
    int start = TicTacToe::Start;

    CHECK(start == 0);
}