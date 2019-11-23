// Copyright 2019 André Hodapp
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"



int add(int a, int b) {
    return a+b;
}

TEST_CASE("ein Test", "[add]") {
    REQUIRE(add(2 , 2)== 4);
}