// Farneback dense optical flow calculate and show in Munsell system of colors
// Author : Zouxy
// Date   : 2013-3-15
// HomePage : http://blog.csdn.net/zouxy09
// Email  : zouxy09@qq.com

// API calcOpticalFlowFarneback() comes from OpenCV, and this
// 2D dense optical flow algorithm from the following paper:
// Gunnar Farneback. "Two-Frame Motion Estimation Based on Polynomial Expansion".
// And the OpenCV source code locate in ..\opencv2.4.3\modules\video\src\optflowgf.cpp

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>


#include "opencv2\opencv.hpp"
#include "opencv\cv.h"
#include "opencv\highgui.h"

#include "FileSearch.h"

using namespace cv;
using namespace std;


void SaveKeyFrame(const Mat& frame, const int frameCount)
{
	stringstream ss;
	ss << "../data/image";
	ss << setfill('0') << setw(3) << frameCount;
	ss << ".jpg";

	string fileName(ss.str());
	imwrite(fileName, frame);
}

void Image2Video(const char* imagePath, const char* videoPath="")
{
	// get all image files name
	std::vector<string> files;
	FO::FindAllFiles(imagePath, files, "*.jpg");

	// get image size
	Mat frame = imread(files[0]);
	Size videoSize = frame.size();

	// create output video
	VideoWriter outputVideo;
	char videoFileName[_MAX_PATH];
	sprintf(videoFileName, "%s/output.avi", videoPath);
	if (!outputVideo.open(videoFileName, CV_FOURCC('M', 'J', 'P', 'G'), 25, videoSize))
	{
		printf("Create output vide failed\n");
		return;
	}
	
	namedWindow("output video", cv::WINDOW_NORMAL);

	unsigned int frameCount = 0;
	for (std::vector<string>::iterator it = files.begin(); it != files.end(); it++,frameCount++)
	{
		std::string fileName = *it;
		frame = imread(fileName);
		
		if (frame.empty())
			break;

		outputVideo << frame;

		imshow("output video", frame);

		if (cv::waitKey(20) == 'q')
			break;
	}

	printf("Create video %s, %d frames\n", videoFileName, frameCount);

}

void MontageVideo(const char* inputPath, const char* outputPath="")
{
	std::vector<string> files;
	FO::FindAllFiles(inputPath, files, "*.avi");

	if (!files.size())
	{
		printf("No files in the input path\n");
		return;
	}

	VideoCapture cap;
	VideoWriter outputVideo;
	if (!cap.open(files[0]))
	{
		printf("Can not open the file \n");
		return;
	}

	// video size
	Mat frame;
	Size videoSize = frame.size();

	// output video
	char outputFilePath[_MAX_PATH];
	sprintf(outputFilePath, "%s/output.avi", outputPath);
	if (!outputVideo.open(outputFilePath, CV_FOURCC('M', 'J', 'P', 'G'), 25, videoSize))
	{
		printf("Can not open output file\n");
		return;
	}

	namedWindow("output video", cv::WINDOW_NORMAL);

	unsigned int frameCount = 0;
	for (std::vector<string>::iterator it = files.begin(); it != files.end(); it++)
	{
		if (!cap.open(*it))
			break;

		while (true)
		{
			cap >> frame;
			
			if (frame.empty())
				break;

			outputVideo << frame;
			imshow("output video", frame);

			frameCount++;

			// next video
			if (cv::waitKey(2) == 'n')
				break;
		}

		if (cv::waitKey(2) == 'q')
			break;
	}

	printf("Create output video %s, %d frames\n", outputFilePath, frameCount);
}


int main(int, char**)
{
	Image2Video("I:/Open Source Code/OPENCV310/tracker benchmark/Walking/img", "I:/Open Source Code/OPENCV310/tracker benchmark/Walking/img");
	Image2Video("I:/Open Source Code/OPENCV310/tracker benchmark/Walking2/img", "I:/Open Source Code/OPENCV310/tracker benchmark/Walking2/img");
	Image2Video("I:/Open Source Code/OPENCV310/tracker benchmark/Bolt/img", "I:/Open Source Code/OPENCV310/tracker benchmark/Bolt/img");
	Image2Video("I:/Open Source Code/OPENCV310/tracker benchmark/Jogging/img", "I:/Open Source Code/OPENCV310/tracker benchmark/Jogging/img");
	Image2Video("I:/Open Source Code/OPENCV310/tracker benchmark/Subway/img", "I:/Open Source Code/OPENCV310/tracker benchmark/Subway/img");
	Image2Video("I:/Open Source Code/OPENCV310/tracker benchmark/Woman/img", "I:/Open Source Code/OPENCV310/tracker benchmark/Woman/img");
	return 0;
}