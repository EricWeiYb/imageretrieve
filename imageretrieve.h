#ifndef __IMAGE__RETRIEVE__
#define __IMAGE__RETRIEVE__

#include <iostream>

enum EORROR_FLAG
{
	MEMORY_ERROR
}

class ImageRetrieve
{
public:
	MEMORY_ERROR ReadInform();
	MEMORY_ERROR Retrieve(const vector<double> &feature, const vector<vector<double>> &featureLib);
	double Compare(const vector<double> &featureA, const vector<double> &featureB);
};


#endif