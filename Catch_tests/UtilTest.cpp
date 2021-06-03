//
// Created by marvd on 01.06.2021.
//

#include "catch.hpp"
#include "Util.h"
#include <cmath>

TEST_CASE("set_bits function") {
    std::array<int, 3> bits{0, 1, 4};
    double expected_result = (1 << 0) + (1 << 1) + (1 << 4);

    int result = Util::set_bits(bits);

    CHECK(expected_result == result);
}

TEST_CASE("set_bit function") {
    int exponent = 4;
    SECTION("using pow function") {
        CHECK(pow(2, exponent) == Util::set_bit(exponent));
    }

    SECTION("using bit shift") {
        CHECK((1 << exponent) == Util::set_bit(exponent));
    }
}