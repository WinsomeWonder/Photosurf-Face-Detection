#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
#include <string>

using namespace cv;
using namespace std;

int main( int argc, char** argv )
{
	string input;
	Mat image;

	while(1)
	{
		cout <<"Input the image you would like to display or type done" << endl;

	    getline(cin, input);

		if(input.compare("done") == 0)
		{
			cout<< "Goodbye!" << endl;
			exit(0);
		}

		image = imread(input, CV_LOAD_IMAGE_COLOR);   // Read the file

		if(! image.data )                              // Check for invalid input
		{
			cout <<  "Could not open or find the image" << std::endl;
		}
		else
		{
			namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
			imshow( "Display window", image );                   // Show our image inside it.
			waitKey(0);								// Wait for a keystroke in the window
	
		}
	}
}