#pragma once
#include <vector>
#include "ship.h"
#include "vectors.h"

using namespace std;

namespace Asteroids
{
	namespace utilities
	{
		class Configuration
		{
		public:
			std::vector<std::vector<Engine::Math::Vectors>> LoadModels() const;
		};
	}
}

