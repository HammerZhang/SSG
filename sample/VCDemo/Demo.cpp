#include <iostream>
//#include <cv.h>
//#include <highgui.h>
//#include <opencv2\highgui\highgui.hpp>
//#include <opencv2\core.hpp>
//#include <opencv2\opencv.hpp>
#include <opencv2\opencv.hpp>
#include <opencv\cv.h>
#include <opencv\highgui.h>

#include "package_bgs/PBAS/PixelBasedAdaptiveSegmenter.h"
#include "package_tracking/BlobTracking.h"
#include "package_analysis/VehicleCouting.h"

int main(int argc, char **argv)
{
	std::cout << "Using OpenCV " << CV_MAJOR_VERSION << "." << CV_MINOR_VERSION << "." << CV_SUBMINOR_VERSION << std::endl;

	/* Open video file */
	//CvCapture *capture = 0;
	//capture = cvCaptureFromAVI("I:\\Open Source Code\\Vehicle_counting\\simple_vehicle_counting\\build\\dataset\\video.avi");
	//if(!capture){
	//  std::cerr << "Cannot open video!" << std::endl;
	//  return 1;
	//}
	cv::VideoCapture capture;
	capture.open("..\\..\\..\\data\\video.avi");
	if (!capture.isOpened())
	{
		std::cerr << "cant not open video!" << std::endl;
		return -1;
	}

	/* Background Subtraction Algorithm */
	IBGS *bgs;
	bgs = new PixelBasedAdaptiveSegmenter;

	/* Blob Tracking Algorithm */
	cv::Mat img_blob;
	BlobTracking* blobTracking;
	blobTracking = new BlobTracking;

	/* Vehicle Counting Algorithm */
	VehicleCouting* vehicleCouting;
	vehicleCouting = new VehicleCouting;

	std::cout << "Press 'q' to quit..." << std::endl;
	int key = 0;
	//IplImage *frame;
	cv::Mat frame;
	while (key != 'q')
	{
		//frame = cvQueryFrame(capture);
		capture >> frame;
		if (frame.empty()) break;

		//cv::Mat img_input(frame);
		//cv::Mat img_input = cv::cvarrToMat(frame);
		cv::Mat img_input = frame.clone();
		cv::imshow("Input", img_input);

		// bgs->process(...) internally process and show the foreground mask image
		cv::Mat img_mask;
		bgs->process(img_input, img_mask);

		if (!img_mask.empty())
		{
			// Perform blob tracking
			blobTracking->process(img_input, img_mask, img_blob);

			// Perform vehicle counting
			vehicleCouting->setInput(img_blob);
			vehicleCouting->setTracks(blobTracking->getTracks());
			vehicleCouting->process();
		}

		key = cv::waitKey(1);
	}

	delete vehicleCouting;
	delete blobTracking;
	delete bgs;

	cv::destroyAllWindows();
	//cvReleaseCapture(&capture);

	return 0;
}
