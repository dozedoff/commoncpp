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

#include <gtest/gtest.h>
#include <limits>
#include "util/Bit.hpp"

TEST(BitTest, ZeroRotateSigned) {
	int64_t testValue = 0;

	int64_t result = Bit::rotateLeft(testValue);

	ASSERT_EQ(0, result);
}

TEST(BitTest, OneRotateSigned) {
	int64_t testValue = 1;

	int64_t result = Bit::rotateLeft(testValue);

	ASSERT_EQ(2, result);
}

TEST(BitTest, DoubleRotateSigned) {
	int64_t testValue = 1;
	int64_t result;

	result = Bit::rotateLeft(testValue);
	result = Bit::rotateLeft(result);

	ASSERT_EQ(4, result);
}

TEST(BitTest, MinusOneRotateSigned) {
	int64_t testValue = -1;

	int64_t result = Bit::rotateLeft(testValue);

	ASSERT_EQ(-1, result);
}

TEST(BitTest, MinusTwoRotateSigned) {
	int64_t testValue = -2;

	int64_t result = Bit::rotateLeft(testValue);

	ASSERT_EQ(-3, result);
}

TEST(BitTest, MaxNegativeRotateSigned) {
	int64_t testValue = std::numeric_limits<int64_t>::min();

	int64_t result = Bit::rotateLeft(testValue);

	ASSERT_EQ(1, result);
}

TEST(BitTest, Rotate31Signed) {
	int64_t testValue = 1;
	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 31; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(2147483648, result);
}

TEST(BitTest, Rotate32Signed) {
	int64_t testValue = 1;
	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 32; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(4294967296, result);
}

TEST(BitTest, Rotate63Signed) {
	int64_t testValue = 1;
	int64_t expected = std::numeric_limits<int64_t>::min();

	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 63; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(expected, result);
}

TEST(BitTest, Rotate64Signed) {
	int64_t testValue = 1;
	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 64; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(1, result);
}

TEST(BitTest, RotateUnsigned) {
	uint64_t testValue = 1;

	int64_t result = testValue;
	result = Bit::rotateLeft(result);

	ASSERT_EQ(2, result);
}

TEST(BitTest, Rotate63Unsigned) {
	uint64_t testValue = 1;
	uint64_t expected = 9223372036854775808ul;
	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 63; i++) {
		result = Bit::rotateLeft(result);
	}
	ASSERT_EQ(expected, result);
}

TEST(BitTest, Rotate64Unsigned) {
	uint64_t testValue = 1;
	int i = 0;

	int64_t result = testValue;

	for (i = 0; i < 64; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(1, result);
}
