#include "leerModels.h"

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

void utilities::printFile()
{
	int length = this->dir.size();
	for (int i = 2; i < length; i++)
	{
		cout << "File name: " << this->dir.at(i) << endl;
	}
}
