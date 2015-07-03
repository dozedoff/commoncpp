/* The MIT License (MIT)
 * Copyright (c) 2014 Nicholas Wright
 * http://opensource.org/licenses/MIT
 */

/*
 * SHA.hpp
 *
 *  Created on: 23 Dec 2013
 *      Author: Nicholas Wright
 */

#ifndef SHA_HPP_
#define SHA_HPP_

#include <boost/filesystem.hpp>
#include <log4cplus/logger.h>

class SHA {
public:
	std::string sha256(boost::filesystem::path filepath);
	SHA();
	virtual ~SHA();

private:
	static const int FILE_BUFFER_SIZE = 2048;

	log4cplus::Logger logger;
};

#endif /* SHA_HPP_ */
