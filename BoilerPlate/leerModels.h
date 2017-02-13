#pragma once

#include <vector>
#include <string>

using namespace std;

namespace Engine
{
	namespace FileSystem
	{
		class utilities
		{
		public:
		
			string BuildPath(string prefix, string sufix);
			vector<std::string> ListFiles(string dir, string wildcard = "*.*");
		private:
			
			string GetExeFileName();
			string GetExePath();
			string GetLocalPathExpr(string dir);
			string GetLocalPathExpr(string dir, string wildcard);
		};
	}
}





/*
class utilities
{
public:
	/*string getPath(string file);
	void ListFile(string file);
	string BuildPath(string prefix, string sufix);
	
	string BuildPath(string prefix, string sufix);
	vector<string> ListFiles(string dir, string wildcard = "*.*");



private:
	/*vector<string> dir;
	void printFile();
	
	string GetExeFileName();
	string GetExePath();
	string GetLocalPathExpr(string dir);
	string GetLocalPathExpr(string dir, string wildcard);
};
*/
