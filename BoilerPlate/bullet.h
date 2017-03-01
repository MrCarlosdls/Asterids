#pragma once
#include <vector>
#include "vectors.h"
#include "entity.h"

using namespace std;

namespace Asteroids
{
	namespace Entities
	{
		class Bullets : public Entity
		{
		public:
			Bullets(Engine::Math::Vectors position,
				Engine::Math::Vectors velocidad, float angulo, 
				unsigned int maxFrameLifeTime = 120);

			void Update(double deltaTime) override;
			void Render() override;
			
		private:
			unsigned int m_framelife;
			unsigned int m_maxframelife;
		};

	}

}