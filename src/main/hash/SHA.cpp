/* The MIT License (MIT)
 * Copyright (c) 2014 Nicholas Wright
 * http://opensource.org/licenses/MIT
 */

/*
 * SHA.cpp
 *
 *  Created on: 23 Dec 2013
 *      Author: Nicholas Wright
 */

#include "hash/SHA.hpp"
#include <openssl/sha.h>
#include <boost/iostreams/device/file.hpp>
#include <boost/filesystem/fstream.hpp>
#include <sstream>
#include <iomanip>

using namespace boost::log::trivial;

std::string SHA::sha256(boost::filesystem::path filepath) {
	if (!boost::filesystem::exists(filepath)) {
		BOOST_LOG_SEV(logger,error) << "File " << filepath << " does not exist";
		return "";
	}

	unsigned char digest[SHA256_DIGEST_LENGTH];
	boost::filesystem::ifstream targetFile;

	targetFile.open(filepath, std::ios::in | std::ios::app | std::ios::binary);

	SHA256_CTX sha256;
	SHA256_Init(&sha256);

	std::istreambuf_iterator<char> eos;
	std::istreambuf_iterator<char> ite(targetFile);

	int readCount = 0;

	while (ite != eos) {
		char byte = *ite;
		SHA256_Update(&sha256, &byte, sizeof(*ite));

		ite++;
		readCount++;
	}

	SHA256_Final(digest, &sha256);
	targetFile.close();

	BOOST_LOG_SEV(logger,debug) << "Read " << readCount << " bytes from " << filepath;

	std::ostringstream os;
	    os << std::hex << std::setfill('0');  // set the stream to hex with 0 fill

	    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
	    	os << std::setw(2) << (unsigned int)(digest[i]);
	    }

	return os.str();
}

SHA::~SHA() {
	// TODO Auto-generated destructor stub
}

