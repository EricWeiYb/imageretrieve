#include "stdafx.h"
#include "mathfunction.h"

/*
double MathFunction::Compare(const vector<double> &featureA, 
			const vector<double> &featureB)
{
	double distance(0);
	if(featureA.size() != featureB.size())
	{
		return -1;
	}
	int size = featureA.size();
	return EulaDistan;
}
*/

double MathFunction::VectorDot(const vector<double> &featureA,
				const vector<double> &featureB)
{
	double temp(0);
	if(featureA.size() != featureB.size())
	{
		return -1;
	}
	int size = featureA.size();
	for(size_t i = 0; i != size; ++i)
	{
		temp += featureA[i] * featureB[i]; 
	}
	return temp;
}



double MathFunction::VectorLength(const vector<double> &feature)
{
	double temp(0);
	for(size_t i = 0; i != feature.size(); ++i)
	{
		temp += feature[i] * feature[i];
	}
}



int MathFunction::VectorSub(const vector<double> &featureA,
				const vector<double> &featureB,
				vector<double> &output)
{
	if(featureA.size() != featureB.size())
	{
		return -1;
	}
	output.clear();
	int size = featureA.size();
	for(size_t i = 0; i != size; ++i)
	{
		output.push_back(featureA[i] - featureB[i]); 
	}
	return 1;
}


int MathFunction::VectorMul(const vector<double> &featureA,
				const vector<double> &featureB,
				vector<double> &output)
{
	if(featureA.size() != featureB.size())
	{
		return -1;
	}
	output.clear();
	int size = featureA.size();
	for(size_t i = 0; i != size; ++i)
	{
		output.push_back(featureA[i] + featureB[i]); 
	}
	return 1;
}

