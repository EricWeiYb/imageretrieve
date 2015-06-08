
#ifndef __MATH__FUNCTION__
#define __MATH__FUNCTION__



int VectorMul(const vetor<double> &featureA,const vector<double> &featureB,vector<double> &output);



int VectorSub(const vetor<double> &featureA,const vector<double> &featureB,vector<double> &output);



double VectorLength(const vector<double> &feature);


double VectorDot(const vetor<double> &featureA,const vector<double> &featureB);


double Compare(const vector<double> &featureA, const vector<double> &featureB);


#endif