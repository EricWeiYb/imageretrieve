#ifndef __EXTRACT__FEATURE__
#define __EXTRACT__FEATURE__
#include <cv.h>
#include <highgui\highgui.hpp>
#include <string>
#include "io.h"

enum EXTRACT_MANNER
{
	HIST
};

using namespace cv;
class ExtractFeature
{
public:
	ExtractFeature(void);
	~ExtractFeature(void);
	void process(const string &path,const string &outPath,EXTRACT_MANNER);
	void process(const string &path,vector<double> &data,EXTRACT_MANNER manner);
private:
	void GetHist(const Mat &image,vector<double> &data);
	void AccumulatedHistogram(Mat &inputImage,vector<double> &histogramArray);
	void ToString(const string &path,vector<double> &data,string &output);
};

#endif