#pragma once
#include <vector>
#include "ship.h"

using namespace std;

namespace Asteroids
{
	namespace utilities
	{
		class Configuration
		{
		public:
			vector<Entities::Ship*> LoadModels(); 
		};
	}
}

