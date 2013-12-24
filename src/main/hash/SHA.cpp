/* The MIT License (MIT)
 * Copyright (c) <2013> <Nicholas Wright>
 * http://opensource.org/licenses/MIT
 */

/*
 * SHA.cpp
 *
 *  Created on: 23 Dec 2013
 *      Author: Nicholas Wright
 */

#include "../../include/hash/SHA.hpp"
#include <openssl/sha.h>
#include <boost/iostreams/device/file.hpp>
#include <boost/filesystem/fstream.hpp>

using namespace log4cplus;

SHA::SHA() {
	logger = Logger::getInstance(LOG4CPLUS_TEXT("SHA"));
}

std::string SHA::sha256(boost::filesystem::path filepath) {
	if (!boost::filesystem::exists(filepath)) {
		LOG4CPLUS_ERROR(logger, "File " << filepath << " does not exist");
		return "";
	}

	unsigned char digest[SHA256_DIGEST_LENGTH];
	char * fileBuffer;
	fileBuffer = new char[FILE_BUFFER_SIZE];

	boost::filesystem::ifstream targetFile;

	targetFile.open(filepath, std::ios::out | std::ios::app | std::ios::binary);

	SHA256_CTX sha256;
	SHA256_Init(&sha256);

	while (!targetFile.eof()) {
		unsigned int read = targetFile.readsome(fileBuffer, FILE_BUFFER_SIZE);
		SHA256_Update(&sha256, fileBuffer, read);
	}

	SHA256_Final(digest, &sha256);
	targetFile.close();

	return std::string(*digest,SHA256_DIGEST_LENGTH);
}

SHA::~SHA() {
	// TODO Auto-generated destructor stub
}

