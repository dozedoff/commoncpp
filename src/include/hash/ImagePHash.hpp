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

using namespace std;

class ImagePHash {
public:
	typedef boost::multi_array<double, 2> dctMatrix;
	typedef dctMatrix::index index;

	ImagePHash();
	ImagePHash(int, int);
	long getLongHash(string);
	dctMatrix createMatrix(void);
private:
	int size;
	int smallerSize;
	double *c; //TODO replace this with a vector

	void initCoefficients();
	long convertToLong(dctMatrix, double);
	double calcDctAverage(dctMatrix);
	dctMatrix applyDCT(dctMatrix);
	void init();
};



#endif /* IMAGEPHASH_HPP_ */
