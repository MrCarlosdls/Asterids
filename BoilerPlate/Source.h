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
	cout << "Pegue la ruta del directorio que quiere abrir: " << endl;
	string dir;
	getline(cin, dir);
	listdir(dir);
	init();
}

void leerenterprise()
{

	ifstream archivo1;
	archivo1.open("enterprise.points");
	string archivos_enterprise[100];
	int count = 0;

	while(!archivo1.eof())
	{
		archivo1 >> archivos_enterprise[count];
		count++;
	}
	
	for (int i = 0; i < 0; i++)
	{
		cout << archivos_enterprise[i] << endl;
	}
}



