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

/*
   Takes in an input array and spits out an output
*/
int FaceDetector::skinTonePixels(cv::Mat input)
{
	int count = 0;

	for(int r = 0; r < input.rows - SMALLEST_SIZE; r++)
	{
		for(int c = 0; c < input.cols - SMALLEST_SIZE; c++)
		{/*
			if(r > 1300)
			{
			   cout << "row " << r << " col " << c << " total rows " << input.rows << " total cols " << input.cols << endl;
			}*/
			cv::Vec3b pix = input.at<cv::Vec3b>(r,c);

			//inRange will change the value within the threshold to 255
			if(pix[0] == 255 && 
				pix[1] == 255 &&
				pix[2] == 255)
			{
				count++;
			}
		}
	}

	return count;
}

