#pragma once
#include <vector>
#include "vectors.h"
#include "entity.h"
#include "bullet.h"

typedef std::vector<Engine::Math::Vectors> points_set;

namespace Asteroids
{
	namespace Entities
	{
		class Ship : public Entity
		{
		public:
			explicit Ship(const std::vector<points_set> ships);
			~Ship();

			void MoveUp() const;
			void MoveRight() const;
			void MoveLeft() const;
			void ChangeShip();
			void Update(double deltaTime) override;
			void Render() override;
			void Respawn();
			Bullets* Shoot() const;
		private:
			void CalculateMass();
			std::vector<points_set> m_ships;
			float m_currentSpeed;
			int	m_currentIndex;
			int m_nRespawnTime;
			bool m_pulse = false;
			int  m_currentPulseCount;
			int  m_totalPulseCount;
			Engine::Math::Vectors1 m_currentColor;
		};
	}
}
