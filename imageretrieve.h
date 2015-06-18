#ifndef __IMAGE__RETRIEVE__
#define __IMAGE__RETRIEVE__

#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <sstream>
#include "io.h"

using namespace std;

enum ERROR_FLAG
{
	MEMORY_ERROR,
	OK
};
typedef map<string,vector<double>> FeatureBase;

struct FeatureDistance
{
	string inform;
	double distance;
};
typedef vector<FeatureDistance> DistanceRank;


struct FeatureRank
{
	std::vector<double> feature;
	DistanceRank rank;
};


class ImageRetrieve
{
public:
	ERROR_FLAG ReadInform();
	ERROR_FLAG Retrieve(FeatureRank &featureRank,FeatureBase &dataBase);
	ERROR_FLAG GetSampleBase(const vector<string> &sampleBase,FeatureBase &dataBase,const int &size);
	ERROR_FLAG GetSampleBase(const string &path,FeatureBase &dataBase,const int &size);
	ERROR_FLAG WriteResult(const FeatureRank &rank,string &path);
private:
	ERROR_FLAG Compare(const std::vector<double> &featureA,FeatureBase &dataBase,DistanceRank &distanceRank);
	double GetDistance(const std::vector<double> &featureA,const std::vector<double> &featureB);
	ERROR_FLAG FeatureSort(DistanceRank &rank);
	static bool SortManner(FeatureDistance &a,FeatureDistance &b);
};


#endif
