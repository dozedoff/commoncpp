/* The MIT License (MIT)
 * Copyright (c) 2014 Nicholas Wright
 * http://opensource.org/licenses/MIT
 */

/*
 * ImagePHash.hpp
 *
 *  Created on: 4 Aug 2013
 *      Author: nicholas
 */

#ifndef IMAGEPHASH_HPP_
#define IMAGEPHASH_HPP_

#include <string>
#include <boost/multi_array.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/sources/severity_logger.hpp>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>

class ImagePHash {
public:
	typedef boost::multi_array<double, 2> dctMatrix;
	typedef dctMatrix::index index;

	ImagePHash();
	ImagePHash(int, int);

	long getLongHash(std::string);
	long getLongHash(cv::Mat &image_data);
	long getLongHash(std::vector<unsigned char> image_data);
	dctMatrix createMatrix(void);

private:
	int size;
	int smallerSize;
	std::vector<double> c;
	boost::log::sources::severity_logger<boost::log::trivial::severity_level> logger;

	void initCoefficients();
	long convertToLong(dctMatrix, double);
	double calcDctAverage(dctMatrix);
	dctMatrix applyDCT(dctMatrix);
	void init();
};

#endif /* IMAGEPHASH_HPP_ */
