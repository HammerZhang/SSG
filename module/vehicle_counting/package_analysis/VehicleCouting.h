#pragma once

#include <iostream>
#include <string>
#include <cv.h>
#include <highgui.h>
#include <opencv2\highgui\highgui.hpp>
#include <opencv2\imgproc\imgproc.hpp>

#include "../package_tracking/cvblob/cvblob.h"

enum LaneOrientation
{
	LO_NONE = 0,
	LO_HORIZONTAL = 1,
	LO_VERTICAL = 2
};

enum VehiclePosition
{
	VP_NONE = 0,
	VP_A = 1,
	VP_B = 2
};

class __declspec(dllexport) VehicleCouting
{
public:
	char configPath[_MAX_PATH];
private:
	bool firstTime;
	bool showOutput;
	int key;
	cv::Mat img_input;
	cvb::CvTracks tracks;
	std::map<cvb::CvID, std::vector<CvPoint2D64f> > points;
	LaneOrientation laneOrientation;
	std::map<cvb::CvID, VehiclePosition> positions;
	long countAB;
	long countBA;
	int img_w;
	int img_h;
	int showAB;

public:
	VehicleCouting();
	~VehicleCouting();

	void setInput(const cv::Mat &i);
	void setTracks(const cvb::CvTracks &t);
	void process();

	void setConfigPath(const char* cf);

private:
	VehiclePosition getVehiclePosition(const CvPoint2D64f centroid);

	void saveConfig();
	void loadConfig();
};
