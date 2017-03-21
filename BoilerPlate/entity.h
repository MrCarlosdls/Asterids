#pragma once

#include <vector>
#include "vectors.h"
#include "GameObject.h"
#include "componenteDeTransformacion.h"
#include "cuerpoRigido.h"
#include "AABB.h"

namespace Asteroids
{
	namespace Entities
	{
		class Entity : public Engine::Core::GameObject
		{
		public:
			struct EntityState
			{
				enum State
				{
					NORMAL = 0, COLLIDED=1, DELETED=2, RESPAWNING=3
				};

			};
			Entity();

			void Update(double delta) override;
			void Render(unsigned int mode, std::vector<Engine::Math::Vectors> points, Engine::Math::Vectors1 color = Engine::Math::Vectors1(1.0));

			bool IsColliding(Entity* rhs);
			bool CanCollide() const { return m_canCollide; }
			void SetCollision(bool canCollide) { m_canCollide = canCollide; }
			Engine::Math::Vectors GetPosition() const { return m_transforms->GetPosition(); }
			bool ShouldBeDeleted() const { return m_state == EntityState::State::DELETED; }
			bool IsColliding() const { return m_state == EntityState::State::COLLIDED; }
			bool IsRespawning() const { return m_state == EntityState::State::RESPAWNING; }

		protected:
			EntityState::State m_state;
			Engine::Components::componenteDeTransformacion* m_transforms;
			Engine::Components::componenteRigido* m_physics;
			float m_radius; 
			bool m_canCollide;
			AABB* Test;
			
		private:
			float m_halfWidth;
			float m_halfHeight;
		};
	}
}

