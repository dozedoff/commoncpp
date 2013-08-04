/*
 * pHashTest.cpp
 *
 *  Created on: 25 Jul 2013
 *      Author: nicholas
 */

#include <gtest/gtest.h>
#include <iostream>
#include "../../include/hash/ImagePHash.hpp"
#include <GraphicsMagick/Magick++.h>

using namespace Magick;

TEST(ImagePHashTest, sizeTest) {
	ASSERT_EQ(1600,1600);
}

int main(int argc, char **argv) {
::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}


