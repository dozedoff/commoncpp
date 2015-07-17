/* The MIT License (MIT)
 * Copyright (c) 2014 Nicholas Wright
 * http://opensource.org/licenses/MIT
 */

/*
 * BitTest.cpp
 *
 *  Created on: 10 Aug 2013
 *      Author: nicholas
 */

#include <catch.hpp>
#include <limits>
#include "util/Bit.hpp"

TEST_CASE( "ZeroRotateSigned", "[BitTest]") {
	int64_t testValue = 0;

	int64_t result = Bit::rotateLeft(testValue);

	REQUIRE(0L==result);
}

TEST_CASE( "OneRotateSigned", "[BitTest]") {
	int64_t testValue = 1;

	int64_t result = Bit::rotateLeft(testValue);

	REQUIRE(2L==result);
}

TEST_CASE( "DoubleRotateSigned", "[BitTest]") {
	int64_t testValue = 1;
	int64_t result;

	result = Bit::rotateLeft(testValue);
	result = Bit::rotateLeft(result);

	REQUIRE(4L==result);
}

TEST_CASE( "MinusOneRotateSigned", "[BitTest]") {
	int64_t testValue = -1;

	int64_t result = Bit::rotateLeft(testValue);

	REQUIRE(-1L==result);
}

TEST_CASE( "MinusTwoRotateSigned", "[BitTest]") {
	int64_t testValue = -2;

	int64_t result = Bit::rotateLeft(testValue);

	REQUIRE(-3L==result);
}

TEST_CASE( "MaxNegativeRotateSigned", "[BitTest]") {
	int64_t testValue = std::numeric_limits<int64_t>::min();

	int64_t result = Bit::rotateLeft(testValue);

	REQUIRE(1L==result);
}

TEST_CASE( "Rotate31Signed", "[BitTest]") {
	int64_t testValue = 1;
	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 31; i++) {
		result = Bit::rotateLeft(result);
	}

	REQUIRE(2147483648L==result);
}

TEST_CASE( "Rotate32Signed", "[BitTest]") {
	int64_t testValue = 1;
	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 32; i++) {
		result = Bit::rotateLeft(result);
	}

	REQUIRE(4294967296L==result);
}

TEST_CASE( "Rotate63Signed", "[BitTest]") {
	int64_t testValue = 1;
	int64_t expected = std::numeric_limits<int64_t>::min();

	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 63; i++) {
		result = Bit::rotateLeft(result);
	}

	REQUIRE(expected==result);
}

TEST_CASE( "Rotate64Signed", "[BitTest]") {
	int64_t testValue = 1;
	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 64; i++) {
		result = Bit::rotateLeft(result);
	}

	REQUIRE(1L==result);
}

TEST_CASE( "RotateUnsigned", "[BitTest]") {
	uint64_t testValue = 1;

	int64_t result = testValue;
	result = Bit::rotateLeft(result);

	REQUIRE(2L==result);
}

TEST_CASE( "Rotate63Unsigned", "[BitTest]") {
	uint64_t testValue = 1;
	uint64_t expected = 9223372036854775808ul;
	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 63; i++) {
		result = Bit::rotateLeft(result);
	}
	REQUIRE(expected==result);
}

TEST_CASE("Rotate64Unsigned", "[BitTest]") {
	uint64_t testValue = 1;
	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 64; i++) {
		result = Bit::rotateLeft(result);
	}

	REQUIRE(1L==result);
}
