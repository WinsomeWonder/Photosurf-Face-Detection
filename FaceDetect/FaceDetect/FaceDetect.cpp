/*
   FaceDetect.cpp

   Emily Ledbetter

   2/28/1014

*/

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "FaceDetect.h"

FaceDetector::FaceDetector(void)
{
}

FaceDetector::~FaceDetector(void)
{
}

int FaceDetector::getFaces(cv::Mat image, std::list<cv::Mat> faces)
{
	cv::Mat skinMask = skin.getSkin(image);

	int count = 0;

    for(int r = 0; r < skinMask.rows - SMALLEST_SIZE; r++)
	{
	}

	return 0;
}



/*******************************************************************************************/
/*                               Skin Detector Access Methods                              */
/*******************************************************************************************/

/*

*/
void FaceDetector::thresholdChange(int yMin, int yMax, int crMin, int crMax, int cbMin, int cbMax)
{
	skin.changeThreshold(yMin, yMax, crMin, crMax, cbMin, cbMax);
}

/*
   Takes in an input array and spits out an output
*/
int FaceDetector::skinTonePixels(cv::Mat input)
{
	cv::Mat skinMask = skin.getSkin(input);

	return skin.skinTonePixels(skinMask);
}

cv::Mat FaceDetector::skinMasking(cv::Mat input)
{
	return skin.getSkin(input);
}

