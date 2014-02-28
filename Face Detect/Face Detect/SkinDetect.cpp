/*
      SkinDetector.h

	  Emily Ledbetter
	  2/27/2014

	  Originally based on code by Raza Chandra Deb found here:
	  http://razibdeb.wordpress.com/2013/09/10/skin-detection-in-c-using-opencv/

      Geared towards positive error:
	     Neutral backgrounds
		 Light Hair Colors
*/

#include "SkinDetector.h"
#include"opencv2\opencv.hpp"
#include "opencv2\core\core.hpp"

SkinDetector::SkinDetector(void)
{
   //YCrCb threshold
   // You can change the values and see what happens
   Y_MIN  = 0;
   Y_MAX  = 255;
   Cr_MIN = 133;
   Cr_MAX = 173;
   Cb_MIN = 77;
   Cb_MAX = 127;
}

SkinDetector::~SkinDetector(void)
{
}

//this function will return a skin masked image
cv::Mat SkinDetector::getSkin(cv::Mat input)
{
   cv::Mat skin;
   //first convert our RGB image to YCrCb
   cv::cvtColor(input,skin,cv::COLOR_BGR2YCrCb);

   //uncomment the following line to see the image in YCrCb Color Space
   //cv::imshow("YCrCb Color Space",skin);

   //filter the image in YCrCb color space
   cv::inRange(skin,cv::Scalar(Y_MIN,Cr_MIN,Cb_MIN),cv::Scalar(Y_MAX,Cr_MAX,Cb_MAX),skin);

   return skin;
}

void SkinDetector::changeThreshold(int yMin, int yMax, int crMin, int crMax, int cbMin, int cbMax)
{
	SkinDetector::Y_MIN = yMin;
	SkinDetector::Y_MAX = yMax;
	SkinDetector::Cr_MIN = crMin;
	SkinDetector::Cr_MAX = crMax;
	SkinDetector::Cb_MIN = cbMin;
	SkinDetector::Cb_MAX = cbMax;
}

int SkinDetector::skinTonePixels(cv::Mat input)
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

//end of SkinDetector.cpp file