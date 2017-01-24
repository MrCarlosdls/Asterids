#include <iostream>
#include <dirent.h>
#include <fstream>
#include <string>

using namespace std;

void listdir(string dir)
{
	DIR * directorio;
	struct dirent * elemento;
	string elem;
	if (directorio = opendir(dir.c_str()))
	{
		while (elemento = readdir(directorio))
		{
			elem = elemento->d_name;
			cout << elem << endl;

		}
	}
	closedir(directorio);
}
void init()
{
	cout << "Ruta del directorio a listar : " << endl;
	string dir;
	getline(cin, dir);
	listdir(dir);
	init();

}


#pragma once
