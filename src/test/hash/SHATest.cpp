/* The MIT License (MIT)
 * Copyright (c) 2014 Nicholas Wright
 * http://opensource.org/licenses/MIT
 */

/*
 * SHATest.cpp
 *
 *  Created on: 24 Dec 2013
 *      Author: Nicholas Wright
 */

#include <gtest/gtest.h>
#include <iostream>
#include "../../include/hash/SHA.hpp"

TEST(SHATest, sha256Binary_Image) {
	SHA sha;
	std::string hash = sha.sha256(boost::filesystem::path("src/test/hash/testImage.jpg"));
	ASSERT_EQ("1acd0ad088779e7089ff2b5a7e7d23ab0d164ca66fa84d4d400c8eb8e6a9db66",hash);
}

TEST(SHATest, sha256Text_empty) {
	SHA sha;
	std::string hash = sha.sha256(boost::filesystem::path("src/test/hash/empty"));
	ASSERT_EQ("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855",hash);
}

TEST(SHATest, sha256Text_abc) {
	SHA sha;
	std::string hash = sha.sha256(boost::filesystem::path("src/test/hash/abc.dat"));
	ASSERT_EQ("ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad",hash);
}

TEST(SHATest, sha256Text_abcdbcde) {
	SHA sha;
	std::string hash = sha.sha256(boost::filesystem::path("src/test/hash/abcdbcde.dat"));
	ASSERT_EQ("248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1",hash);
}

TEST(SHATest, sha256Text_a_1m) {
	SHA sha;
	std::string hash = sha.sha256(boost::filesystem::path("src/test/hash/a_1m.dat"));
	ASSERT_EQ("cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0",hash);
}
