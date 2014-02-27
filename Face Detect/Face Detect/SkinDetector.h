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

#pragma once
#include<opencv\cv.h>
using namespace std;
class SkinDetector
{
   public:
      SkinDetector(void);
      ~SkinDetector(void);

   /*
      Masks skin
   */
   cv::Mat getSkin(cv::Mat input);

   void changeThreshold(int yMin, int yMax, int crMin, int crMax, int cbMin, int cbMax);

   private:
      int Y_MIN;
      int Y_MAX;
      int Cr_MIN;
      int Cr_MAX;
      int Cb_MIN;
      int Cb_MAX;
};

// end of SkinDetector.h file