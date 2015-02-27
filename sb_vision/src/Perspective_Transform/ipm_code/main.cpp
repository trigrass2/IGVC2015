/*
 * Project:  Inverse Perspective Mapping
 *
 * File:     main.cpp
 *
 * Contents: Creation, initialisation and usage of IPM object
 *           for the generation of Inverse Perspective Mappings of images or videos
 *
 * Author:   Marcos Nieto <marcos.nieto.doncel@gmail.com>
 * Date:	 22/02/2014
 * Homepage: http://marcosnietoblog.wordpress.com/
 */

#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>
#include <ctime>

#include "IPM.h"

using namespace cv;
using namespace std;

int main( int _argc, char** _argv )
{

    VideoCapture cap(0); // open the video camera no. 0

    if (!cap.isOpened())  // if not success, exit program
    {
cout << "Cannot open the video cam" << endl;
        return -1;
    }

   double dWidth = cap.get(CV_CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
   double dHeight = cap.get(CV_CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

    cout << "Frame size : " << dWidth << " x " << dHeight << endl;

    namedWindow("MyVideo",CV_WINDOW_AUTOSIZE); //create a window called "MyVideo"

    while (1)
    {
        Mat frame;

        bool bSuccess = cap.read(frame); // read a new frame from video

if (!bSuccess) //if not success, break loop
{
cout << "Cannot read a frame from video stream" << endl;
break;
}

        imshow("MyVideo", frame); //show the frame in "MyVideo" window

        if (waitKey(30) == 27) //wait for 'esc' key press for 30ms. If 'esc' key is pressed, break loop
{
cout << "esc key is pressed by user" << endl;
break; 
}
    }
    return 0;

}
/*
	// Images
	Mat inputImg, inputImgGray;
	Mat outputImg;
	
	if( _argc != 2 )
	{
		cout << "Usage: ipm.exe <videofile>" << endl;
		return 1;
	}

	// Video
	string videoFileName = _argv[1];	
	cv::VideoCapture video;
	if( !video.open(videoFileName) ) {
		cout <<"Video Error" << endl;
		return 1;
	}

	// Show video information
	int width = 0, height = 0, fps = 0, fourcc = 0;	
	width = static_cast<int>(video.get(CV_CAP_PROP_FRAME_WIDTH));
	height = static_cast<int>(video.get(CV_CAP_PROP_FRAME_HEIGHT));
	fps = static_cast<int>(video.get(CV_CAP_PROP_FPS));
	fourcc = static_cast<int>(video.get(CV_CAP_PROP_FOURCC));

	cout << "Input video: (" << width << "x" << height << ") at " << fps << ", fourcc = " << fourcc << endl;
	
	// The 4-points at the input image	
	vector<Point2f> origPoints;
	origPoints.push_back( Point2f(0, height-40) );
	origPoints.push_back( Point2f(width-100, height-40) );
	origPoints.push_back( Point2f(width/2-20, 200) );
	origPoints.push_back( Point2f(width/2-110, 200) );

	// The 4-points correspondences in the destination image
	vector<Point2f> dstPoints;
	dstPoints.push_back( Point2f(0, height) );
	dstPoints.push_back( Point2f(width, height) );
	dstPoints.push_back( Point2f(width, 0) );
	dstPoints.push_back( Point2f(0, 0) );
		
	// IPM object
	IPM ipm( Size(width, height), Size(width, height), origPoints, dstPoints );
	
	// Main loop
	int frameNum = 0;
	for( ; ; )
	{
		printf("FRAME #%6d ", frameNum);
		fflush(stdout);
		frameNum++;

		// Get current image		
		video >> inputImg;
		if( inputImg.empty() )
			break;

		 // Color Conversion
		 if(inputImg.channels() == 3)		 
			 cvtColor(inputImg, inputImgGray, CV_BGR2GRAY);				 		 
		 else	 
			 inputImg.copyTo(inputImgGray);			 		 

		 // Process
		 clock_t begin = clock();
		 ipm.applyHomography( inputImg, outputImg );		 
		 clock_t end = clock();
		 double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
		 printf("%.2f (ms)\r", 1000*elapsed_secs);
		 ipm.drawPoints(origPoints, inputImg );

		 // View		
		 imshow("Input", inputImg);
		 imshow("Output", outputImg);
		 waitKey(1);
	}

	return 0;	
}		
*/