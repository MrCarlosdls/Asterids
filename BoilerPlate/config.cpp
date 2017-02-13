#include "config.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "leerModels.h"
#include "Vectors.h"

using namespace std;

namespace Asteroids
{
	namespace utilities
	{
		string const models_dir = "models";

		vector<Entities::Ship*> Configuration::LoadModels()
		{
			Engine::FileSystem::utilities util;

			auto models = util.ListFiles(models_dir);

			vector<Entities::Ship*> ships;

			for (auto model : models)
			{
			
				ifstream ifstream(util.BuildPath(models_dir, model));
			
				string content;

				vector<Engine::Math::Vectors> points;
				while (ifstream >> content)
				{
			
					stringstream lineStream(content);
					string cell;
				    vector<float> components;
					while (getline(lineStream, cell, ','))
					{
						components.push_back(stof(cell));
					}
					points.push_back(
						Engine::Math::Vectors(components[0], components[1])
					);
				}

				ships.push_back(new Asteroids::Entities::Ship(points));
			}

			return ships;
		}
	}
}