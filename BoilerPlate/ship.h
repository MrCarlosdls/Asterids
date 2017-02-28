#pragma once
#include <vector>
#include "vectors.h"
#include "entity.h"

typedef std::vector<Engine::Math::Vectors> points_set;

namespace Asteroids
{
	namespace Entities
	{
		class Ship : public Entity
		{
		public:
			Ship(const std::vector<points_set> ships);
			~Ship();

			void MoveUp() const;
			void MoveRight() const;
			void MoveLeft() const;
			void ChangeShip();
			void Update(float deltaTime) override;
			void Render() override;
			void Respawn();

			Engine::Math::Vectors GetPosition() const { return m_transforms->GetPosition(); };
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
