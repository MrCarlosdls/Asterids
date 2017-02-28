#pragma once

#include "componente.h"
#include "vectors.h"

namespace Engine
{
	namespace Components
	{
		class componenteRigido : public Core::Component
		{
		public:
			componenteRigido();
			componenteRigido(Math::Vectors gravity, Math::Vectors position, float mass = 1.0f, float dragFactor = 1.0f);
			~componenteRigido();

			void Update(float deltaTime) override;
			void ApplyForce(const Math::Vectors force, float angleInRadians = 1.0f);
			void SetMass(float mass) { m_mass = mass; }
			void SetVelocity(Math::Vectors velocity) { m_velocity = velocity; }
			float GetMass() const { return m_mass; }
			float GetSpeed() const { return m_velocity.Length(); }
			Math::Vectors GetVelocity() const { return m_velocity; }
		protected:
			
			float m_mass;
			float m_drag;
			Math::Vectors m_position;
			Math::Vectors m_force;
			Math::Vectors m_gravity;
			Math::Vectors m_velocity;
		};
	}
}
