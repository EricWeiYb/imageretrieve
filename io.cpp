#include "io.h"


IOProcess::IOProcess(void)
{
}


IOProcess::~IOProcess(void)
{
}


void IOProcess::ReadFile(const string &path,const vector<string> &features)
{
	FILE *fp;
	char szBuf[1000];
    ifstream infile(path);
    while(infile.getline(szBuf,1000))
    {
    	istringstream s(szBuf)
    	string path;
    	s>>path;
    	features.push_back(path);
    }
    infile.close();
    return;
}




void  IOProcess::WriteFile(const string &path,const vector<string> &features)
{
	string temp;
	for (std::vector<string>::iterator i = features.begin(); i != features.end(); ++i)
	{
		temp = (*i) + "\n";
		Write(path,(*i).str());
	}
	data<<"\n";
	
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