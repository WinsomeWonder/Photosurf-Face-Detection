#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>
#include "SkinDetector.h"

using namespace cv;
using namespace std;

void processImage(string input, SkinDetector detect);
void end(void);
void thresholdChange(string input, SkinDetector detect);

int main( int argc, char** argv )
{

	string input;
    SkinDetector detect;

	while(1)
	{
		cout <<"Input the image you would like to display, type change threshold, or type done" << endl;

		/*Proper use: Needs to be system path!!!*/
	    getline(cin, input);

		if(input.compare("done") == 0)
		{
			end();
		}

		if(input.compare("change threshold") == 0)
		{
			thresholdChange(input, detect);
		}

		processImage(input, detect);
	}
}

void processImage(string input, SkinDetector detect)
{
	
	Mat image;
	Mat skinMasked;
	image = imread(input, CV_LOAD_IMAGE_COLOR);   // Read the file

	if(! image.data )                              // Check for invalid input
	{
		cout <<  "Could not open or find the image" << std::endl;
	}
	else
	{
		cout << "Here is the original image" << endl;
		namedWindow( "Original Image", WINDOW_AUTOSIZE );// Create a window for display.
		imshow( "Original Image", image );                   // Show our image inside it.
		waitKey(0);								// Wait for a keystroke in the window

		skinMasked = detect.getSkin(image);
		cout << "Here is the skin detected image" << endl;
		namedWindow("Masked Skin Image", WINDOW_AUTOSIZE);
		imshow("Masked Skin Image", skinMasked);
		waitKey(0);								// Wait for a keystroke in the window
	}
}


/*IT'S THE END AND IT DOESN'T EVEN MATTER*/
void end(void)
{
	cout<< "Goodbye!" << endl;
	exit(0);
}

/* Change Threshold helper */
void thresholdChange(string input, SkinDetector detect)
{
	size_t pos;
	int yMin,yMax, crMin, crMax, cbMin, cbMax;

	cout<< "Please input crMin" << endl;
	getline(cin, input);
	crMin = stoul(input, &pos, 10);

    cout<< "Please input crMax" << endl;
	getline(cin, input);
	crMax = stoul(input, &pos, 10);

	cout<< "Please input cbMin" << endl;
	getline(cin, input);
	cbMin = stoul(input, &pos, 10);

	cout<< "Please input cbMax" << endl;
	getline(cin, input);
	cbMax = stoul(input, &pos, 10);

	/* OBSERVATIONS
	   yMin and yMax do not seem to make much of a difference
	*/
	detect.changeThreshold(0, 255, crMin, crMax, cbMin, cbMax);
}