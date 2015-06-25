#ifndef __CLUSTER__
#define __CLUSTER__


#include "mathfunction.h"
#include "distancemanner.h"

struct FeatureStruct
{
	vector<double> feature;
	string inform;	
};

struct ClusterStruct
{
	vector<size_t> samples;
	int center;
};

class Cluster
{
public:
	void LoadSamples(const string &path,vector<FeatureStrcut> &samples);
	void InitFeatureInform(const int &featureDimension,const int &clusterCount);
	void ClusteProcess(vector<FeatureStrcut> &samples,const int &maxCicleCount);
	void GetCluster(FeatureStrcut &feature,int &cluster);
	void GetClusterCenter(vector<FeatureStrcut> &samples,vector<int> &indexVec,const int &featureDimension,const int &clusterIndex);
	double GetClusterVal(vector<FeatureStrcut> &samples,vector<int> &indexVec,const int &clusterIndex);
	void ReleaseClusterInform();

private:
	int centerCount;
	int featureDim;
	vector<FeatureStruct> featureCenters;
	vector<ClusterStruct> clusterInform;
	Distance getDistance;
	MathFunction math;
};
#endif