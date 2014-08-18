#include "opencv.hpp"
#include "highgui.hpp"

float* cvMat2floatArray(cv::Mat source)
{
	float* result = (float*)malloc(source.rows*source.cols*3*sizeof(float));;
	float* tempFloat;
	cv::Mat tempMat;
	int resultIndex=0;

	//first, we need the type conversion
	source.convertTo(tempMat, CV_32FC3, 1.0/255.0);
	tempFloat = (float*)tempMat.data;

	//the next step is changing the way the rows, columns and channels are arranged
	for (int channel=0; channel < 3; channel++)
		for (int column=0; column < source.cols; column++)
			for (int row=0; row < source.rows; row++)
			{
				//teste1: 
				result[resultIndex++] = 	tempFloat[column*3 				+row*source.cols*3 	+channel];
				//teste2: 
				//result[resultIndex++] = 	tempFloat[column*source.rows*3 	+row*3 				+channel];
				//teste3: 
				//result[resultIndex++] 	= 	tempFloat[column 				+row*source.cols	+channel*source.rows*source.cols];
				//teste4: 
				//result[resultIndex++] = 	tempFloat[column*source.rows	+row				+channel*source.rows*source.cols];
			}

	return result;
}

cv::Mat floatArray2cvMat(float* source, int rows, int cols, int type)
{
	cv::Mat result(rows, cols, type);
	float* tempFloat = (float*)malloc(rows*cols*3*sizeof(float));
	int tempIndex=0;

	for (int channel=0; channel < 3; channel++)
		for (int column=0; column < cols; column++)
			for (int row=0; row < rows; row++)
			{
				//teste1: 
				tempFloat[column*3 		+row*cols*3 	+channel] 			= source[tempIndex++];
				//teste2: 
				//tempFloat[column*rows*3 	+row*3 			+channel] 			= source[tempIndex++];
				//teste3: 
				//tempFloat[column 			+row*cols 		+channel*rows*cols] = source[tempIndex++];
				//teste4: 
				//tempFloat[column*rows		+row			+channel*rows*cols] = source[tempIndex++];
			}

	result.data = (uchar*)tempFloat;

	return result;
}

void print_array(float *v, int n) {
	std::cout << "print_array" << std::endl;
	for (int i=0; i<n; ++i)
		std::cout << v[i];
	std::cout << std::endl;
}


int main() {

	cv::Mat image = cv::imread("./simple.png");
	
	cv::Mat fimage;
	image.convertTo(fimage, CV_32FC3, 1/255.0);
	print_array((float*)fimage.data, fimage.cols*fimage.rows*3);

	float* I;
	I = cvMat2floatArray(image);

	print_array(I, image.cols*image.rows*3);

	cv::Mat testMat;
	testMat = floatArray2cvMat(I, image.rows, image.cols, CV_32FC3);

	return 0;

}