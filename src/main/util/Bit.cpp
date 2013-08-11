/*
 * Bit.cpp
 *
 *  Created on: 10 Aug 2013
 *      Author: nicholas
 */

#include "../../include/util/Bit.hpp"

long long Bit::rotateLeft(const long long value) {
	unsigned long long unsig = value;
	return Bit::rotateLeft(unsig);
}

unsigned long long Bit::rotateLeft(const unsigned long long value) {
	return (value << 1) | (value >> (sizeof(value)*8 - 1));
}


