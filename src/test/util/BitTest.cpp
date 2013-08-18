/*
 * BitTest.cpp
 *
 *  Created on: 10 Aug 2013
 *      Author: nicholas
 */
#include <gtest/gtest.h>
#include <limits>
#include "../../include/util/Bit.hpp"

TEST(BitTest, ZeroRotate) {
	int64_t testValue = 0;
	int64_t result = -1;

	result = Bit::rotateLeft(testValue);

	ASSERT_EQ(0, result);
}

TEST(BitTest, OneRotate) {
	int64_t testValue = 1;
	int64_t result = -1;

	result = Bit::rotateLeft(testValue);

	ASSERT_EQ(2, result);
}

TEST(BitTest, DoubleRotate) {
	int64_t testValue = 1;
	int64_t result = -5;

	result = Bit::rotateLeft(testValue);
	result = Bit::rotateLeft(result);

	ASSERT_EQ(4, result);
}

TEST(BitTest, MinusOneRotate) {
	int64_t testValue = -1;
	int64_t result = 0;

	result = Bit::rotateLeft(testValue);

	ASSERT_EQ(-1, result);
}

TEST(BitTest, MaxNegativeRotate) {
	int64_t testValue = std::numeric_limits<int64_t>::min();
	int64_t result = -2;

	result = Bit::rotateLeft(testValue);

	ASSERT_EQ(1, result);
}

TEST(BitTest, Rotate31) {
	int64_t testValue = 1;
	int64_t result = -2;
	int i = 0;

	result = testValue;

	for(i = 0; i < 31; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(2147483648, result);
}

TEST(BitTest, Rotate32) {
	int64_t testValue = 1;
	int64_t result = -2;
	int i = 0;

	result = testValue;

	for(i = 0; i < 32; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(4294967296, result);
}

TEST(BitTest, Rotate63Signed) {
	int64_t testValue = 1;
	int64_t result = -2;
	int64_t expected = -9223372036854775808;

	int i = 0;

	result = testValue;

	for(i = 0; i < 63; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(expected, result);
}

TEST(BitTest, Rotate64) {
	int64_t testValue = 1;
	int64_t result = -2;
	int i = 0;

	result = testValue;

	for(i = 0; i < 64; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(1, result);
}

TEST(BitTest, Rotate63Unsigned) {
	uint64_t testValue = 1;
	uint64_t result = -2;
	int i = 0;

	result = testValue;

	for(i = 0; i < 63; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(1, result);
}
