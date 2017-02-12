#pragma once
#include <vector>
#include "Vectors.h"
#include "entity.h"

namespace Asteroids
{
	namespace Entities
	{
		class Ship : public Entity
		{
		public:
			
			Ship(const std::vector<Engine::Math::Vectors> points);

			void MoveUp();
			void Draw();
		private:
			std::vector<Engine::Math::Vectors> m_points;
		};
	}
}