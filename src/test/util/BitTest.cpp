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
	long long testValue = 0;
	long long result = -1;

	result = Bit::rotateLeft(testValue);

	ASSERT_EQ(0, result);
}

TEST(BitTest, OneRotate) {
	long long testValue = 1;
	long long result = -1;

	result = Bit::rotateLeft(testValue);

	ASSERT_EQ(2, result);
}

TEST(BitTest, DoubleRotate) {
	long long testValue = 1;
	long long result = -5;

	result = Bit::rotateLeft(testValue);
	result = Bit::rotateLeft(result);

	ASSERT_EQ(4, result);
}

TEST(BitTest, MinusOneRotate) {
	long long testValue = -1;
	long long result = 0;

	result = Bit::rotateLeft(testValue);

	ASSERT_EQ(-1, result);
}

TEST(BitTest, MaxNegativeRotate) {
	long long testValue = std::numeric_limits<long long>::min();
	long long result = -2;

	result = Bit::rotateLeft(testValue);

	ASSERT_EQ(1, result);
}

TEST(BitTest, Rotate31) {
	long long testValue = 1;
	long long result = -2;
	int i = 0;

	result = testValue;

	for(i = 0; i < 31; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(2147483648, result);
}

TEST(BitTest, Rotate32) {
	long long testValue = 1;
	long long result = -2;
	int i = 0;

	result = testValue;

	for(i = 0; i < 32; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(4294967296, result);
}

TEST(BitTest, Rotate63) {
	long long testValue = 1;
	long long result = -2;
	int i = 0;

	result = testValue;

	for(i = 0; i < 63; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(9223372036854775808, result);
}

TEST(BitTest, Rotate64) {
	long long testValue = 1;
	long long result = -2;
	int i = 0;

	result = testValue;

	for(i = 0; i < 64; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(1, result);
}

TEST(BitTest, Rotate64Unsigned) {
	unsigned long long testValue = 1;
	unsigned long long result = -2;
	int i = 0;

	result = testValue;

	for(i = 0; i < 64; i++) {
		result = Bit::rotateLeft(result);
	}

	ASSERT_EQ(1, result);
}
