#pragma once

#include <vector>
#include "vectors.h"
#include "GameObject.h"
#include "componenteDeTransformacion.h"
#include "cuerpoRigido.h"

namespace Asteroids
{
	namespace Entities
	{
		class Entity : public Engine::Core::GameObject
		{
		public:
			Entity();

			void Update(float delta) override;
			void Render(unsigned int mode, std::vector<Engine::Math::Vectors> points, Engine::Math::Vectors1 color = Engine::Math::Vectors1(1.0));
			bool IsColliding(Entity* rhs) const;
			bool CanCollide() const { return m_canCollide; }
			void SetCollision(bool canCollide) { m_canCollide = canCollide; }
		protected:
			Engine::Components::componenteDeTransformacion* m_transforms;
			Engine::Components::componenteRigido* m_physics;
			float m_radius; 
			bool m_canCollide;
		private:
			float m_halfWidth;
			float m_halfHeight;
		};
	}
}

