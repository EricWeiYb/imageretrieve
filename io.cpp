#include "io.h"


IOProcess::IOProcess(void)
{
}


IOProcess::~IOProcess(void)
{
}


void IOProcess::ReadFile(const string &path,const vector<double> &features,const vector<string> &inform)
{
	void ReadClassify(const string &path,vector<vector<int>> &data)
{
	FILE *fp;
	char szBuf[1000];
    ifstream infile(path);
    while(infile.getline(szBuf,1000))
    {
    	istringstream s(szBuf)
    	double classify(0);
    	int height(0);
    	int width(0);
    	s>>classify>>height>>width;
    	temp.push_back(classify);
    	temp.push_back(height);
    	temp.push_back(width);
    	data.push_back(temp);
    }
    infile.close();
    return;
}
}




void  IOProcess::WriteFile(const string &path,const vector<double> &features,const string &inform)
{
	ostringstream data;
	data<<inform<<" ";
	for (std::vector<double>::iterator i = features.begin(); i != features.end(); ++i)
	{
		data<<(*i)<<" ";
	}
	data<<"\n";
	Write(path,data.str());
}




void IOProcess::Write(const string &path,const string &data)
{
	FILE *fp;
	fp=fopen(path.c_str(),"a");
	if (!fp)
	{
		return;
	}
	fwrite(data.c_str(),data.size(),1,fp);
	fclose(fp);
}