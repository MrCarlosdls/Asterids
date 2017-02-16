#pragma once
#include <vector>
#include "Vectors.h"
#include "entity.h"


using namespace std;

namespace Asteroids
{
	namespace Entities
	{
		class Ship : public Entity
		{
		public:
			
			Ship(const vector<Engine::Math::Vectors> points);

			void MoveUp();
			void MoveDown();
			void MoveRight();
			void MoveLeft();
			void Draw();
		private:
			vector<Engine::Math::Vectors> m_points;
			
		};
	}
}