#pragma once
#include <vector>
#include "vectors.h"
#include "entity.h"
#include <stdlib.h>
#include <time.h>




using namespace std;

namespace Asteroids
{
	namespace  Entities
	{
		class Asteroid : public Entity
		{
		public:
			
		
			struct AsteroidSize
			{
				enum Size
				{
					BIG = 0,
					MEDIUM = 1,
					SMALL = 2,
				};
			};

			explicit Asteroid(AsteroidSize::Size size, Engine::Math::Vectors position = Engine::Math::Vectors::Origin);
			void Update(double deltaTime) override;
			void Render() override;
			void ApplyRandomTranslation() const;

			AsteroidSize::Size GetSize() const { return m_size; };
		private:
			
			void Generate();
			void ApplyRandomImpulse() const;

			std::vector<Engine::Math::Vectors> m_points;
			AsteroidSize::Size m_size;
			int m_sizeFactor;
		};
	}
}
