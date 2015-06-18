#ifndef __IO_PROCESS__
#define __IO_PROCESS__

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <sstream>


using std::string;
using std::ofstream;
using std::ifstream;
using std::ostringstream;
using std::vector;
using std::istringstream;
using std::ostringstream;


class IOProcess
{
public:
	IOProcess(void);
	~IOProcess(void);
	void ReadFile(const string &path,vector<string> &features);
	void WriteFile(const string &path,vector<string> &features);
	void Write(const string &path,const string &data);
};

#endif
