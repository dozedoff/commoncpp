/* The MIT License (MIT)
 * Copyright (c) 2014 Nicholas Wright
 * http://opensource.org/licenses/MIT
 */

/**
 * @file test_main.cpp
 *
 * @date 3 Jul 2015
 * @author Nicholas Wright
 * @brief an undocumented file
 * 
 * Some more details about this file.
 */

#include <gtest/gtest.h>
#include <log4cplus/configurator.h>
#include <GraphicsMagick/Magick++.h>

int main(int argc, char **argv) {
	 log4cplus::BasicConfigurator config;
	 config.configure();
::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
