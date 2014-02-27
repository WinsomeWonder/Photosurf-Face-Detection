//SkinDetector.cpp
//Based on
//http://razibdeb.wordpress.com/2013/09/10/skin-detection-in-c-using-opencv/
//Raza Chandra Deb
//
//Edited by Emily K Ledbetter
//

#include "SkinDetector.h"
#include"opencv2\opencv.hpp"

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

//end of SkinDetector.cpp file