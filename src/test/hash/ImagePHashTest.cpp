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

#include <gtest/gtest.h>
#include <iostream>
#include "hash/ImagePHash.hpp"
#include <GraphicsMagick/Magick++.h>

TEST(ImagePHashTest, hashImage) {
	ImagePHash iph(32,9);
	long pHash = iph.getLongHash("src/test/hash/testImage.jpg");
	ASSERT_EQ(4092185452341198848,pHash);
}

TEST(ImagePHashTest, hashImage_resized) {
	ImagePHash iph(32,9);
	long pHash = iph.getLongHash("src/test/hash/testImage_small.jpg");
	ASSERT_EQ(4092185452341198848,pHash);
}

TEST(ImagePHashTest, hashImage_default_settings) {
	ImagePHash iph;
	long pHash = iph.getLongHash("src/test/hash/testImage.jpg");
	ASSERT_EQ(126456442795200,pHash);
}

TEST(ImagePHashTest, hashImage_sampling_image_too_large) {
	ImagePHash iph(32,10);
	ASSERT_THROW(iph.getLongHash("src/test/hash/testImage.jpg"), std::invalid_argument);
}
