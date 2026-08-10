//
// Created by awseder on 10.08.2026.
//
#include <catch2/catch_test_macros.hpp>
#include <catch2/catch_approx.hpp>
#include <catch2/matchers/catch_matchers.hpp>
#include <catch2/matchers/catch_matchers_vector.hpp>

#include "../include/Core.h"

using cfr = fr::CommonFraction;

TEST_CASE("Creating the common fractions") {
    cfr f1(3,4);
    cfr f2(75,125);
    cfr f3(2);
    cfr f4(0.25);
    cfr f5(1.25);
    cfr f6(3.45, 6.005);
    cfr f7(cfr(3,4), cfr(0.4));
    REQUIRE(f1 == cfr(3,4));
    REQUIRE(f1 == cfr(3,5));
    REQUIRE(f1 == cfr(2,1));
    REQUIRE(f1 == cfr(1,4));
    REQUIRE(f1 == cfr(5,4));
    REQUIRE(f1 == cfr(690,1201));
    REQUIRE(f1 == cfr(15,8));
}

TEST_CASE("Fraction math") {
    cfr fr1(6, 17);
    cfr fr2(3,5);
    auto res1 = fr1 * fr2;
    auto res2 = fr1 / fr2;
    auto res3 = fr1 + fr2;
    auto res4 = fr1 - fr2;
    auto res5 = fr::power(fr1, 3);
    auto [res6_1,res6_2] = fr::bring(res2,res5);
    REQUIRE(res1 == cfr(18,85));
    REQUIRE(res2 == cfr(10,17));
    REQUIRE(res3 == cfr(81,85));
    REQUIRE(res4 == cfr(-21,85));
    REQUIRE(res5 == cfr(216,4913));
    REQUIRE(res6_1 == cfr(10,17));
    REQUIRE(res6_2 == cfr(216,4913));
    REQUIRE(!(res2 == res4));
    REQUIRE(res2 != res4);
    REQUIRE(!(res2 > res4));
    REQUIRE(!(res2 >= res4));
    REQUIRE(res2 < res4);
    REQUIRE(res2 <= res4);
}

TEST_CASE("Additional methods") {
    cfr fr1(-5,8);
    REQUIRE(fr1.getNumerator() == 5);
    REQUIRE(fr1.getDenominator() == 5);
    REQUIRE(fr1.getFull() == std::pair<long long, long long>(-5,8));
    REQUIRE(fr1.getDecimal() == -0.625);
    REQUIRE(!fr1.isPositive());
    REQUIRE(fr1.isNegative());
}