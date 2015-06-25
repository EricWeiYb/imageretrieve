#include "cluster.h"


void Cluster::LoadSamples(const string &path,vector<FeatureStrcut> &samples)
{

}



void Cluster::InitFeatureInform(const int &featureDimension,const int &clusterCount)
{
	//初始化聚类个数
	centerCount = clusterCount;
	//初始化特征维数
	featureDim = featureDimension;

	//清空原始特征中心和聚类中心信息
	featureCenters.clear();
	clusterInform.clear();

	//临时变量
	FeatureStruct featureTemp;
	for (int i = 0; i != featureDimension; ++i)
	{
		featureTemp.feature.push_back(0);
	}
	ClusterStruct clusterTemp;


	//初始化聚类中心(全为0)和聚类信息
	for (int i = 0; i != k; ++i)
	{
		featureCenters.push_back(featureTemp);
		clusterInform.push_back(clusterTemp);
	}
}


void Cluster::ClusteProcess(vector<FeatureStrcut> &samples,const int &maxCicleCount)
{
	//总样本个数
	size_t size = samples.size();	
	int cluster(-1);
	//循环次数记录
	int cicleCount(0);
	double oldVal(0);
	double newVal(0);
	while(1)
	{
		//分类信息重置
		ReleaseClusterInform();
		//对所有样本进行重新分类
		for (int index = 0; index != size; ++index)
		{
			//得到分类类别
			GetCluster(samples[index],cluster);
			//记录类别
			clusterInform[cluster].samples.push_back(index);
		}
		//重置聚类中心
		for (int index = 0; index != centerCount; ++index)
		{
			GetClusterCenter(samples,clusterInform[index].samples,featureDim,index);
		}
		//重新计算方差
		for (int index = 0; index != centerCount; ++index)
		{
			newVal += GetClusterVal(samples,clusterInform[index].samples,index);
		}
		//循环次数+1
		cicleCount++;
		//判断是否满足结束条件，如果没有，记录偏差值
		if (abs(oldVal - newVal) < 1 || cicleCount == maxCicleCount)
		{
			break;
		}
		else
		{
			oldVal = newVal;
		}
	}
}

void Cluster::GetCluster(FeatureStrcut &feature,int &cluster)
{
	double temp(0);
	double minDistance(100000000);
	//int cluster(-1);
	for (int i = 0; i != centerCount; ++i)
	{
		temp = getDistance.EluaDistance(feature,featureCenters[i]);
		if (minDistance > temp)
		{
			minDistance = temp;
			cluster = i;
		} 
	}
}


void Cluster::GetClusterCenter(vector<FeatureStrcut> &samples,vector<int> &indexVec,const int &featureDimension,const int &clusterIndex)
{
	sampleSize = indexVec.size();
	std::vector<double> sumTemp(featureDimension,0);
	//所有特征相加
	for (int j = 0; j != sampleSize; ++j)
	{
		math.VectorMul(sumTemp,samples[indexVec[j]],sumTemp);
	}
	//除以特征个数，并记录聚类中心
	for (int z = 0; z != featureDimension; ++z)
	{
		featureCenters[clusterIndex].feature[z] = (sumTemp[z]/sampleSize);
	}
	
}



void Cluster::ReleaseClusterInform()
{
	int size = clusterInform.size();
	for (int i = 0; i != size; ++i)
	{
		clusterInform[i].samples.release();
		clusterInform[i].center = -1;
	}
}

double Cluster::GetClusterVal(vector<FeatureStrcut> &samples,vector<int> &indexVec,const int &clusterIndex)
{
	sampleSize = indexVec.size();
	double valTemp(0);
	for (int j = 0; j != sampleSize; ++j)
	{
		sumTemp += getDistance.EluaDistance(featureCenters[clusterIndex],samples[indexVec[j]]);
	}
	return valTemp/sampleSize;
}


