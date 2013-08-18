/*
 * Bit.hpp
 *
 *  Created on: 10 Aug 2013
 *      Author: nicholas
 */

#ifndef BIT_HPP_
#define BIT_HPP_

#include <inttypes.h>

class Bit {
public:
	static int64_t rotateLeft(const int64_t);
	static uint64_t rotateLeft(const uint64_t);
};

#endif /* BIT_HPP_ */
