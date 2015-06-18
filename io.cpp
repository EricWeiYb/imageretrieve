#include "stdafx.h"
#include "io.h"


IOProcess::IOProcess(void)
{
}


IOProcess::~IOProcess(void)
{
}


void IOProcess::ReadFile(const string &path,vector<string> &features)
{
	char szBuf[100000];
    ifstream infile(path);
    while(infile.getline(szBuf,100000))
    {
    	features.push_back(szBuf);
    }
    infile.close();
    return;
}




void  IOProcess::WriteFile(const string &path,vector<string> &features)
{
	string temp;
	for (std::vector<string>::iterator i = features.begin(); i != features.end(); ++i)
	{
		temp = (*i) + "\n";
		Write(path,(*i));
	}
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