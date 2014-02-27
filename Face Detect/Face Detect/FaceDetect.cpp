
#include "FaceDetect.h"

void RGB2YCbCr(Vec3b rgb, Vec3b YCbCr)
{
}


Mat src;
int main(){
    src = imread("open_1a.jpg");
    if (src.empty())
        return -1;
    blur( src, src, Size(3,3) );
    Mat hsv;
    cvtColor(src, hsv, CV_BGR2HSV);
    Mat bw;
    //inRange(hsv, Scalar(0, 40, 60), Scalar(20, 150, 255), bw);
    inRange(hsv, Scalar(0, 10, 60), Scalar(20, 150, 255), bw);
    imshow("src", src);
    imshow("dst", bw);
    waitKey(0);
    return 0;
}