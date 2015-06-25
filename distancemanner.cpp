#include "stdafx.h"
#include "distancemanner.h"


double Distance::EluaDistance(std::vector<double> featureA,std::vector<double> featureB)
{
	double temp(0);
	int size = featureA.size();
	std::vector<double> subFeature;
	mathfunc.VectorSub(featureA,featureB,subFeature);
	return mathfunc.VectorLength(subFeature);
}
