#if _MSC_VER && _DEBUG
	#define _CRTDBG_MAP_ALLOC
	#include <crtdbg.h>
#endif

#include <cassert>
#include <iostream>
#include <string>
//#include <MMSystem.h>
#include "fstream"
#include "Source.h"
#include "App.hpp"
#include "windows.h"
#include "leerModels.h"

 

using namespace std;
 
const int WIDTH = 1136;
const int HEIGHT = 640;

int main(int argc, char* argv[])
{
#if _MSC_VER && _DEBUG
	// https://msdn.microsoft.com/en-us/library/x98tx3cf.aspx
	// This will help you detect leaks when using Visual C++
	// Uncomment this line to start getting reports!
	assert(_CrtCheckMemory());
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

    //Leeyendo carpeta models
	//utilities DIR;
	//DIR.ListFile("models");

	// Create Game Object
	//
	Application::App* app = new Application::App("Boiler Plate!", WIDTH, HEIGHT);


	//PlaySound("text.wav", NULL, SND_ASYNC | SND_FILENAME | SND_LOOP);

	// Initialize game
	//
	if(!app->Init())
	{
		cout << "App Init error!\n";
		return -1;
	}
	
	// Execute game
	//
	app->Execute();

	// Delete game object
	//
	delete app;

	return 0;
}