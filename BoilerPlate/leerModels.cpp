#include "leerModels.h"
#include <Windows.h>
#include <sstream>

using namespace std;

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
			return string(file.begin(), file.end());
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
			string path = GetLocalPathExpr(dir, wildcard);

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