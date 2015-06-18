
#ifndef __MATH__FUNCTION__
#define __MATH__FUNCTION__

#include <vector>

using std::vector;

class MathFunction
{
public:
	MathFunction();
	~MathFunction();
	int VectorMul(const vector<double> &featureA,const vector<double> &featureB,vector<double> &output);
	int VectorSub(const vector<double> &featureA,const vector<double> &featureB,vector<double> &output);
	double VectorLength(const vector<double> &feature);
	double VectorDot(const vector<double> &featureA,const vector<double> &featureB);
	//double Compare(const vector<double> &featureA, const vector<double> &featureB);	
};





#endif