#ifndef __IMAGE__RETRIEVE__
#define __IMAGE__RETRIEVE__

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

enum EORROR_FLAG
{
	MEMORY_ERROR
}
struct FeatureStruct
{
	std::vector<double> feature;
	string inform;
	double distance;
};


class ImageRetrieve
{
public:
	MEMORY_ERROR ReadInform();
	MEMORY_ERROR Retrieve(const vector<double> &feature, const vector<vector<double>> &featureLib);
	double Compare(const vector<double> &featureA, const vector<double> &featureB);
    MEMORY_ERROR GetSampleBase(string path);
private:
	std::vector<FeatureStruct> samples;
};


#endif