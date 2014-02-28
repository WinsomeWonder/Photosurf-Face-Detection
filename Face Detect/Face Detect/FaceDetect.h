/*
   FaceDetect.h

   Emily Ledbetter
   02/28/2014

   Face Detection 
   
   Uses SkinDetector.h based on YCbCr color space

*/
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <list>

#include "SkinDetector.h"

#define SMALLEST_SIZE 48

class FaceDetector
{
   public:
	   FaceDetector(void);
	   ~FaceDetector(void);

	   void thresholdChange(int yMin, int yMax, int crMin, int crMax, int cbMin, int cbMax);

	   /* 
	      getFaces
		     -image to comb through
			 -the list for the faces
	   
	      returns 0 if no faces, 1 if many
	   */
	   int getFaces(cv::Mat image, std::list<cv::Mat> faces);

	   /* Find the number of skin tone pixels in an image */
	   int skinTonePixels(cv::Mat input);

   private:
	   SkinDetector skin;


};

