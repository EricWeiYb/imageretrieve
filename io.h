#ifndef __IO_PROCESS__
#define __IO_PROCESS__

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>


using std::string;
using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::vector;


class IOProcess
{
public:
	IOProcess(void);
	~IOProcess(void);
	void ReadFile(const string &path,double *data,int width,int height);
	void WriteFile(const string &path,double *data,int width,int height);
	void Write(const string &path,const string &data);
};

#endif
