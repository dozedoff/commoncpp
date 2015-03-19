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

#include <boost/multi_array.hpp>
#include <string>
#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <iomanip>
#include <GraphicsMagick/Magick++.h>
#include <GraphicsMagick/magick/image.h>

using namespace log4cplus;
using namespace std;

class ImagePHash {
public:
	typedef boost::multi_array<double, 2> dctMatrix;
	typedef dctMatrix::index index;

	ImagePHash();
	ImagePHash(int, int);
	~ImagePHash();

	long getLongHash(string);
	long getLongHash(Magick::Blob image_data);
	dctMatrix createMatrix(void);
private:
	int size;
	int smallerSize;
	double *c; //TODO replace this with a vector
	Logger logger;

	void initCoefficients();
	long convertToLong(dctMatrix, double);
	double calcDctAverage(dctMatrix);
	dctMatrix applyDCT(dctMatrix);
	void init();
};



#endif /* IMAGEPHASH_HPP_ */
