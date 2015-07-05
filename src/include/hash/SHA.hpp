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

#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>

class SHA {
public:
	std::string sha256(boost::filesystem::path filepath);

private:
	static const int FILE_BUFFER_SIZE = 2048;

	boost::log::sources::severity_logger< boost::log::trivial::severity_level> logger;
};

#endif /* SHA_HPP_ */
