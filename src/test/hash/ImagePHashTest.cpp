/* The MIT License (MIT)
 * Copyright (c) 2014 Nicholas Wright
 * http://opensource.org/licenses/MIT
 */

/*
 * pHashTest.cpp
 *
 *  Created on: 25 Jul 2013
 *      Author: nicholas
 */

#include <catch.hpp>
#include <iostream>
#include "hash/ImagePHash.hpp"
#include <GraphicsMagick/Magick++.h>

TEST_CASE("hashImage", "[ImagePHashTest]") {
	ImagePHash iph(32, 9);
	long pHash = iph.getLongHash("src/test/hash/testImage.jpg");
	REQUIRE(4092185452341198848 == pHash);
}

TEST_CASE( "hashImage_resized", "[ImagePHashTest]") {
	ImagePHash iph(32, 9);
	long pHash = iph.getLongHash("src/test/hash/testImage_small.jpg");
	REQUIRE(4092185452341198848 == pHash);
}

TEST_CASE( "hashImage_default_settings", "[ImagePHashTest]") {
	ImagePHash iph;
	long pHash = iph.getLongHash("src/test/hash/testImage.jpg");
	REQUIRE(126456442795200 == pHash);
}

TEST_CASE( "hashImage_sampling_image_too_large", "[ImagePHashTest]") {
	ImagePHash iph(32, 10);
	REQUIRE_THROWS_AS(iph.getLongHash("src/test/hash/testImage.jpg"), std::invalid_argument);
}
