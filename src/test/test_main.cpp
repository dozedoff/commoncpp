/* The MIT License (MIT)
 * Copyright (c) 2014 Nicholas Wright
 * http://opensource.org/licenses/MIT
 */

/**
 * @file test_main.cpp
 *
 * @date 3 Jul 2015
 * @author Nicholas Wright
 * @brief Google test runner
 * 
 * This file runs all the tests.
 */

#include <gtest/gtest.h>
#include <GraphicsMagick/Magick++.h>

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
