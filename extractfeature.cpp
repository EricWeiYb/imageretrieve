#include "stdafx.h"
#include "extractfeature.h"


ExtractFeature::ExtractFeature(void)
{
}


ExtractFeature::~ExtractFeature(void)
{
}

void ExtractFeature::process(const string &path,const string &outPath,EXTRACT_MANNER manner)
{
	string data;
	IOProcess io;
	Mat image = imread(path);
	vector<double> featureData;
	switch (manner)
	{
	case HIST:	
		GetHist(image,featureData);	
		ToString(path,featureData,data);
		io.Write(outPath,data);
		break;
	default:
		break;
	}
}



void ExtractFeature::process(const string &path,vector<double> &data,EXTRACT_MANNER manner)
{
	Mat image = imread(path);
	//vector<double> featureData;
	switch (manner)
	{
	case HIST:	
		GetHist(image,data);	
		break;
	default:
		break;
	}
}


void ExtractFeature::ToString(const string &path,vector<double> &data,string &output)
{
	ostringstream stream;
	stream<<path<<" ";
	for (int i = 0; i != 256; ++i)
	{
		stream<<data[i]<<" ";
	}
	stream<<std::endl;
	output = stream.str();
}


void ExtractFeature::GetHist(const Mat &image,vector<double> &data)
{
	Mat gray;
	cvtColor(image,gray,CV_BGR2GRAY,CV_8UC1);
	vector<double> hist(256,0);
	AccumulatedHistogram(gray,hist);
	data = hist;
}


void ExtractFeature::AccumulatedHistogram(Mat &inputImage,vector<double> &histogramArray)
{
	uchar* data;
	//灰度直方图
	for (int row=0;row!=inputImage.rows;++row)
	{
		data = inputImage.ptr<uchar>(row);
		for (int col=0;col!=inputImage.cols;++col)
		{
			histogramArray[(int)data[col]]++;
		}
	}
}
