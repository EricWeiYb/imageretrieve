#include "stdafx.h"
#include "retrievemain.h"




int _tmain(int argc, TCHAR* argv[])
{
	if (argc < 2)
	{
		cout<<argc<<endl;
		system("pause");
		return 0;
	}
	//检索
	ImageRetrieve retrieve;
	FeatureBase dataBase;
	retrieve.GetSampleBase(argv[2],dataBase,atoi(argv[4]));
	FeatureRank rank;
	ExtractFeature extract;
	vector<double> feature;
	extract.process(argv[1],feature,HIST);
	rank.feature = feature;
	retrieve.Retrieve(rank,dataBase);
	string outPath(argv[3]);
	retrieve.WriteResult(rank,outPath);
	
	//提取特征
	/*
	ExtractFeature extract;
	extract.process(argv[1],argv[2],HIST);	
	*/
	system("pause");
	return 0;
}

