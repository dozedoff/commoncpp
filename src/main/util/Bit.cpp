/* The MIT License (MIT)
 * Copyright (c) 2014 Nicholas Wright
 * http://opensource.org/licenses/MIT
 */

/*
 * Bit.cpp
 *
 *  Created on: 10 Aug 2013
 *      Author: nicholas
 */

#include "util/Bit.hpp"

int64_t Bit::rotateLeft(const int64_t value) {
	uint64_t unsig = value;
	return (int64_t)Bit::rotateLeft(unsig);
}

uint64_t Bit::rotateLeft(const uint64_t value) {
	return (value << 1) | (value >> (sizeof(value)*8 - 1));
}


