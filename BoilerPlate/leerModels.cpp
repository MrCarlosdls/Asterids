/*#include "leerModels.h"

#include <sstream>

using namespace std;

string  utilities::getPath(string file)
{
	wchar_t ffs[MAX_PATH];
	GetModuleFileName(NULL, ffs, MAX_PATH);
	wstring w_dir(ffs);
	string s_dir(w_dir.begin(), w_dir.end());
	string path(s_dir.substr(0, s_dir.find_last_of("\\/")));
	path += "\\" + file;
	wstring current(path.begin(), path.end());
	current += L"/*.*";
	return string(current.begin(), current.end());
}

void utilities::ListFile(string file)
{
	string path(this->getPath(file));
	wstring w_path(path.begin(), path.end());
	WIN32_FIND_DATA fileFinder;
	vector<string> vs;
	HANDLE hFind;
	hFind = FindFirstFile(w_path.c_str(), &fileFinder);

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			wstring fname(fileFinder.cFileName);
			vs.push_back(string(fname.begin(), fname.end()));
		} while (FindNextFile(hFind, &fileFinder));
	}
	FindClose(hFind);

	this->dir = vs;
	this->printFile();
}

string utilities::BuildPath(string prefix, string sufix)
{
	return string();
}

void utilities::printFile()
{
	int length = this->dir.size();
	for (int i = 2; i < length; i++)
	{
		cout << "File name: " << this->dir.at(i) << endl;
	}
	
}
/*string utilities::BuildPath(string prefix, string sufix)
{
	stringstream path;

	path << prefix;
	path << "\\";
	path << sufix;

	return path.str();
}*/

#include "leerModels.h"

// stdlib
#include <Windows.h>
#include <sstream>

namespace Engine
{
	namespace FileSystem
	{
		string utilities::GetExeFileName()
		{
			wchar_t buffer[MAX_PATH];
			GetModuleFileName(NULL, buffer, MAX_PATH);
			wstring w_buff(buffer);
			return string(w_buff.begin(), w_buff.end());
		}

		string utilities::GetExePath()
		{
			string f = GetExeFileName();
			return f.substr(0, f.find_last_of("\\/"));
		}

		string utilities::GetLocalPathExpr(string dir)
		{
			string current = GetExePath() + "\\" + dir;
			wstring s(current.begin(), current.end());
			wstring file = s + L"\\*.*";
			return std::string(file.begin(), file.end());
		}

		string utilities::GetLocalPathExpr(string dir, string wildcard)
		{
		 string current = GetExePath() + "\\" + dir + "\\" + wildcard;
			return current;
		}

		string utilities::BuildPath(string prefix, string sufix)
		{
			stringstream path;

			path << prefix;
			path << "\\";
			path << sufix;

			return path.str();
		}

		vector<string> utilities::ListFiles(string dir, string wildcard)
		{
			// Build the local path
			string path = GetLocalPathExpr(dir, wildcard);

			// Transform
			wstring w_path(path.begin(), path.end());

			WIN32_FIND_DATA FindFileData;

			vector<string> files;


			HANDLE hFind;
			hFind = FindFirstFile(w_path.c_str(), &FindFileData);
			if (hFind != INVALID_HANDLE_VALUE)
			{
				do {
					std::wstring fname(FindFileData.cFileName);
					if (fname == L"." || fname == L"..")
						continue;

					files.push_back(
						std::string(fname.begin(), fname.end())
					);
				} while (FindNextFile(hFind, &FindFileData));
				FindClose(hFind);
			}

			return files;
		}
	}
}