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

#include <catch.hpp>
#include <iostream>
#include "hash/SHA.hpp"

TEST_CASE( "sha256Binary_Image", "[SHATest]") {
	SHA sha;
	std::string hash = sha.sha256(boost::filesystem::path("src/test/hash/testImage.jpg"));
	REQUIRE("3100fc5145acab142a5935b6b9436e53cde05e7382f36dc1e67360b9ff96539b" == hash);
}

TEST_CASE( "sha256Text_empty", "[SHATest]") {
	SHA sha;
	std::string hash = sha.sha256(boost::filesystem::path("src/test/hash/empty"));
	REQUIRE("e3b0c44298fc1c149afbf4c8996fb92427ae41e4649b934ca495991b7852b855"== hash);
}

TEST_CASE( "sha256Text_abc", "[SHATest]") {
	SHA sha;
	std::string hash = sha.sha256(boost::filesystem::path("src/test/hash/abc.dat"));
	REQUIRE("ba7816bf8f01cfea414140de5dae2223b00361a396177a9cb410ff61f20015ad"== hash);
}

TEST_CASE( "sha256Text_abcdbcde", "[SHATest]") {
	SHA sha;
	std::string hash = sha.sha256(boost::filesystem::path("src/test/hash/abcdbcde.dat"));
	REQUIRE("248d6a61d20638b8e5c026930c3e6039a33ce45964ff2167f6ecedd419db06c1"== hash);
}

TEST_CASE( "sha256Text_a_1m", "[SHATest]") {
	SHA sha;
	std::string hash = sha.sha256(boost::filesystem::path("src/test/hash/a_1m.dat"));
	REQUIRE("cdc76e5c9914fb9281a1c7e284d73e67f1809a48a497200e046d39ccc7112cd0"== hash);
}

TEST_CASE( "sha256_file_not_found", "[SHATest]") {
	SHA sha;
	std::string hash = sha.sha256(boost::filesystem::path("src/test/hash/notfound"));
	REQUIRE(""== hash);
}
