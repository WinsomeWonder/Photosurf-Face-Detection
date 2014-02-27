/*
   Emily Ledbetter
   02/17/2014

   Face Detection based on YCbCr color space

*/
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>

const float Kr = 0.114;
const float Kb = 0.299;

/*
*/
void RGB2YCbCr(Vec3b rgb, Vec3b YCbCr);