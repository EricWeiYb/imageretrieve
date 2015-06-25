#ifndef __DISTANCE__MANNER__
#define __DISTANCE__MANNER__

#include "mathfunction.h"

class Distance
{
public:
	Distance();
	~Distance();
	double EluaDistance(std::vector<double> featureA,std::vector<double> featureB);
private:
	MathFunction mathfunc;
	
};
#endif