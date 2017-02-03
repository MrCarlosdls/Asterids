#pragma once

#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>
#include <iostream>

using namespace std;

class utilities
{
public:
	string getPath(string file);
	void ListFile(string file);

private:
	vector<string> dir;
	void printFile();
};
