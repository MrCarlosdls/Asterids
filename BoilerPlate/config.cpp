#include "config.h"
#include <string>
#include <fstream>
#include <sstream>
#include "leerModels.h"
#include "vectors.h"
#include "mathUtilities.h"

namespace Asteroids
{
	namespace utilities
	{
		std::string const models_dir = "models";

		std::vector<std::vector<Engine::Math::Vectors>> Configuration::LoadModels() const
		{
			Engine::FileSystem::utilities util;

			// Retrieve the files from the models directory
			//
			auto models = util.ListFiles(models_dir);

			std::vector<std::vector<Engine::Math::Vectors>> ships;

			for (auto model : models)
			{
				// Load file
				//
				std::ifstream ifstream(util.BuildPath(models_dir, model));

				//
				std::string content;

				std::vector<Engine::Math::Vectors> points;
				while (ifstream >> content)
				{
					// Read components
					//
					std::stringstream lineStream(content);
					std::string cell;
					std::vector<float> components;
					while (std::getline(lineStream, cell, ','))
					{
						components.push_back(std::stof(cell));
					}

					// Add vector
					//
					points.push_back(
						Engine::Math::Vectors(components[0], components[1])
					);
				}

				// Adding ship to array
				//
				ships.push_back(points);
			}

			return ships;
		}
	}
}