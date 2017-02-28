#include "cuerpoRigido.h"

namespace Engine
{
	namespace Components
	{
		const std::string COMP_NAME = "PHYSICS_COMPONENT";
		componenteRigido::componenteRigido()
			: Component(COMP_NAME)
			, m_gravity(0.0f, 0.0f)
			, m_position(0.0f, 0.f)
			, m_mass(1.0f)
			, m_drag(1.0f)
		{}

		componenteRigido::componenteRigido(Math::Vectors gravity, Math::Vectors position, float mass, float drag)
			: Component(COMP_NAME)
			, m_mass(mass)
			, m_drag(drag)
			, m_position(position)
			, m_gravity(gravity)
		{}

		componenteRigido::~componenteRigido()
		{}

		void componenteRigido::Update(float deltaTime)
		{
			m_velocity += m_gravity;
			m_velocity *= m_drag;

			Component::Update(deltaTime);
		}

		void componenteRigido::ApplyForce(const Math::Vectors force, float angleInRadians)
		{
			if (m_mass > 0)
			{
				float x = (force.m_x / m_mass) * cosf(angleInRadians);
				float y = (force.m_y / m_mass) * sinf(angleInRadians);

				m_velocity += Math::Vectors(x, y);
			}
		}
	}
}