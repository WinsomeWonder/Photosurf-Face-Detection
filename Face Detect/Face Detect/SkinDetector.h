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
	  /*
	     Constructor
	  */
      SkinDetector(void);

	  /*
	     Deconstructor
	  */
      ~SkinDetector(void);

      /*
         Masks skin
      */
      cv::Mat getSkin(cv::Mat input);

      /*
         Changes threshold values from defaults defined in comments
      */
      void changeThreshold(int yMin, int yMax, int crMin, int crMax, int cbMin, int cbMax);

      /*
         Skin Tone Pixel Number
		    Meant for use after being masked
      */
      //int skinTonePixels(cv::Mat input);

   private:
      int Y_MIN; //0
      int Y_MAX; //255
      int Cr_MIN;//133
      int Cr_MAX;//173
      int Cb_MIN;//77
      int Cb_MAX;//127
};

// end of SkinDetector.h file