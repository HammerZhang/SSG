#pragma once

#include <iostream>
#include <cv.h>
#include <highgui.h>

#include "cvblob/cvblob.h"

class __declspec(dllexport) BlobTracking
{
public:
	char configPath[_MAX_PATH];

private:
  bool firstTime;
  int minArea;
  int maxArea;
  
  bool debugTrack;
  bool debugBlob;
  bool showBlobMask;
  bool showOutput;

  cvb::CvTracks tracks;
  void saveConfig();
  void loadConfig();

public:
  BlobTracking();
  ~BlobTracking();

  void process(const cv::Mat &img_input, const cv::Mat &img_mask, cv::Mat &img_output);
  const cvb::CvTracks getTracks();

  void setConfigPath(const char* cf);
};

