#include <string>
#include <cmath>
#include <ImageMagick/Magick++.h>
#include <ImageMagick/magick/image.h>
#include <boost/multi_array.hpp>

using namespace Magick;
using namespace std::string;

class ImagePHash {
public:
	typedef boost::multi_array<double, 2> dctMatrix;
	typedef dctMatrix::index index;

	ImagePHash();
	ImagePHash(int, int);
	long getLongHash(std::string);
	dctMatrix createMatrix(void);
private:
	int size;
	int smallerSize;
	double c[];

	void initCoefficients();
	long convertToLong(dctMatrix, double);
	double calcDctAverage(dctMatrix);
	dctMatrix applyDCT(dctMatrix);
	void init();


};

	ImagePHash::ImagePHash() {
		size = 32;
		smallerSize = 8;
		init();
	}

	ImagePHash::ImagePHash(int size, int smallerSize) {
		this->size = size;
		this->smallerSize = smallerSize;

		init();
	}

	void ImagePHash::init() {
		initCoefficients();


	}

	long ImagePHash::getLongHash(std::string filename) {
		Image img = new Image(filename);
		return 0;
	}

	/**
	 *
	 * @param is
	 *            file to hash
	 * @return hash in as long
	 * @throws IOException
	 */
/*	long getLongHash(ofstream is) {
		double[][] dct = calculateDctMap(is);
		double dctAvg = calcDctAverage(dct);
		long hash = convertToLong(dct, dctAvg);
		return hash;
	}

	long getLongHash(BufferedImage img) throws Exception {
		double[][] dct = calculateDctMap(img);
		double dctAvg = calcDctAverage(dct);
		long hash = convertToLong(dct, dctAvg);
		return hash;
	}*/

	/**
	 *
	 * @param is
	 *            file to hash
	 * @return a 'binary string' (like. 001010111011100010) which is easy to do
	 *         a hamming distance on.
	 * @throws IOException
	 */
/*	public String getHash(InputStream is) throws IOException {
		String hash;
		double[][] dct = calculateDctMap(is);
		double dctAvg = calcDctAverage(dct);
		hash = convertToBitString(dct, dctAvg);

		return hash;
	}*/

/*	private double[][] reduceColor(BufferedImage img) {
		double values[][] = new double[size][size];

		for (int x = 0; x < img.getWidth(); x++) {
			for (int y = 0; y < img.getHeight(); y++) {
				values[x][y] = getBlue(img, x, y);
			}
		}

		return values;
	}*/

/*	public double[][] calculateDctMap(InputStream is) throws IOException {
		BufferedImage img = readImage(is);
		return calculateDctMap(img);
	}

	public double[][] calculateDctMap(BufferedImage img) throws IOException {


		 * 1. Reduce size. Like Average Hash, pHash starts with a small image.
		 * However, the image is larger than 8x8; 32x32 is a good size. This is
		 * really done to simplify the DCT computation and not because it is
		 * needed to reduce the high frequencies.

		img = resize(img, size, size);


		 * 2. Reduce color. The image is reduced to a grayscale just to further
		 * simplify the number of computations.

		img = grayscale(img);

		double[][] vals = reduceColor(img);


		 * 3. Compute the DCT. The DCT separates the image into a collection of
		 * frequencies and scalars. While JPEG uses an 8x8 DCT, this algorithm
		 * uses a 32x32 DCT.

		// long start = System.currentTimeMillis();
		double[][] dctVals = applyDCT(vals);
		// System.out.println("DCT: " + (System.currentTimeMillis() - start));
		// // Removed to prevent system.out spam

		return dctVals;
	}*/

/*	private String convertToBitString(double[][] dctVals, double avg) {

		 * 6. Further reduce the DCT. This is the magic step. Set the 64 hash
		 * bits to 0 or 1 depending on whether each of the 64 DCT values is
		 * above or below the average value. The result doesn't tell us the
		 * actual low frequencies; it just tells us the very-rough relative
		 * scale of the frequencies to the mean. The result will not vary as
		 * long as the overall structure of the image remains the same; this can
		 * survive gamma and color histogram adjustments without a problem.


		String hash = "";

		for (int x = 0; x < smallerSize; x++) {
			for (int y = 0; y < smallerSize; y++) {
				if (x != 0 && y != 0) {
					hash += (dctVals[x][y] > avg ? "1" : "0");
				}
			}
		}
		return hash;
	}*/

	long ImagePHash::convertToLong(dctMatrix dctVals, double avg) {
		if (smallerSize > 9) {
			throw "The selected smallerSize value is to big for the long datatype";
		}

		long hash = 0;

		for (int x = 0; x < smallerSize; x++) {
			for (int y = 0; y < smallerSize; y++) {
				if (x != 0 && y != 0) {
					hash += (dctVals[x][y] > avg ? 1 : 0);
					//hash = Long.rotateLeft(hash, 1); //TODO rotate left in C++
				}
			}
		}
		return hash;
	}

	double ImagePHash::calcDctAverage(dctMatrix dctVals) {
		/*
		 * 4. Reduce the DCT. This is the magic step. While the DCT is 32x32,
		 * just keep the top-left 8x8. Those represent the lowest frequencies in
		 * the picture.
		 */
		/*
		 * 5. Compute the average value. Like the Average Hash, compute the mean
		 * DCT value (using only the 8x8 DCT low-frequency values and excluding
		 * the first term since the DC coefficient can be significantly
		 * different from the other values and will throw off the average).
		 */
		double total = 0;

		for (int x = 0; x < smallerSize; x++) {
			for (int y = 0; y < smallerSize; y++) {
				total += dctVals[x][y];
			}
		}
		total -= dctVals[0][0];

		double avg = total / (double) ((smallerSize * smallerSize) - 1);
		return avg;
	}

/*	private BufferedImage resize(BufferedImage image, int width, int height) {
		BufferedImage resizedImage = new BufferedImage(width, height, BufferedImage.TYPE_INT_ARGB);
		Graphics2D g = resizedImage.createGraphics();
		g.drawImage(image, 0, 0, width, height, null);
		g.dispose();
		return resizedImage;
	}

	private ColorConvertOp colorConvert = new ColorConvertOp(ColorSpace.getInstance(ColorSpace.CS_GRAY), null);

	private BufferedImage grayscale(BufferedImage img) {
		colorConvert.filter(img, img);
		return img;
	}

	private static int getBlue(BufferedImage img, int x, int y) {
		return (img.getRGB(x, y)) & 0xff;
	}*/

	// DCT function stolen from
	// http://stackoverflow.com/questions/4240490/problems-with-dct-and-idct-algorithm-in-java

	void ImagePHash::initCoefficients() {
		c = new double[size];

		for (int i = 1; i < size; i++) {
			c[i] = 1;
		}

		c[0] = 1 / sqrt((double)(2.0)); //sqrt(2.0);
	}

	ImagePHash::dctMatrix ImagePHash::applyDCT(dctMatrix f) {
		int N = size;

		dctMatrix F(boost::extents[N][N]);
		for (int u = 0; u < N; u++) {
			for (int v = 0; v < N; v++) {
				double sum = 0.0;
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < N; j++) {
						sum += std::cos(((2 * i + 1) / (2.0 * N)) * u * M_PI) * std::cos(((2 * j + 1) / (2.0 * N)) * v * M_PI)
								* (f[i][j]);
					}
				}
				sum *= ((c[u] * c[v]) / 4.0);
				F[u][v] = sum;
			}
		}
		return F;
	}

