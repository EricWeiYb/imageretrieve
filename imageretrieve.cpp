#include "stdafx.h"
#include "imageretrieve.h"

ERROR_FLAG ImageRetrieve::Retrieve(FeatureRank &featureRank, 
									FeatureBase &dataBase)
{
	DistanceRank distance;
	Compare(featureRank.feature,dataBase,distance);
	FeatureSort(distance);
	featureRank.rank = distance;
	return OK;
}

ERROR_FLAG ImageRetrieve::WriteResult(const FeatureRank &rank,string &path)
{
	IOProcess io;
	size_t length = rank.rank.size();
	for(int i = 0; i != length; ++i)
	{
		ostringstream stream;
		stream<<rank.rank[i].inform<<"   "<<i<<"   "<<rank.rank[i].distance<<std::endl;
		io.Write(path,stream.str());
		std::cout<<stream.str();
	}
	
	return OK;
}



ERROR_FLAG ImageRetrieve::Compare(const std::vector<double> &featureA,FeatureBase &dataBase,DistanceRank &distanceRank)
{
	distanceRank.clear();
	FeatureDistance temp;
    for(map<string,vector<double>>::iterator iter = dataBase.begin(); iter != dataBase.end();++iter)
    {
    	//cout<<"key: "<<it->first <<" value: "<<it->second<<endl;
    	temp.inform = iter->first;
    	temp.distance = GetDistance(featureA,iter->second);
    	distanceRank.push_back(temp);
    }
	return OK;
}


double ImageRetrieve::GetDistance(const std::vector<double> &featureA,const std::vector<double> &featureB)
{
	double temp(0);
	for (int i = 0; i != featureA.size(); ++i)
	{
		temp += ((featureA[i] - featureB[i])*(featureA[i] - featureB[i]));
	}
	return temp;
}


ERROR_FLAG ImageRetrieve::FeatureSort(DistanceRank &rank)
{
	sort(rank.begin(),rank.end(),this->SortManner);
	return OK;
}



bool ImageRetrieve::SortManner(FeatureDistance &a,FeatureDistance &b)
{
	return a.distance < b.distance;
}


ERROR_FLAG ImageRetrieve::GetSampleBase(const vector<string> &sampleBase,FeatureBase &dataBase,const int &size)
{
	vector<double> feature(size,0);	
	for (size_t i = 0; i != sampleBase.size(); ++i)
	{
		string inform;
		istringstream tempStream(sampleBase[i]);
		tempStream>>inform;
		for (vector<double>::iterator iter = feature.begin(); iter != feature.end(); ++iter)
		{
			double tempval;
			tempStream>>tempval;
			*iter = tempval;
		}
		dataBase.insert(make_pair(inform,feature));
	}
	return MEMORY_ERROR;
}


ERROR_FLAG ImageRetrieve::GetSampleBase(const string &path,FeatureBase &dataBase,const int &size)
{
	IOProcess io;
	vector<string> features;
	io.ReadFile(path,features);
	GetSampleBase(features,dataBase,size);
	return OK;
}