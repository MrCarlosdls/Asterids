#include "componenteDeTransformacion.h"

namespace Engine
{
	namespace Components
	{
		const std::string COMP_NAME = "TRANSFORMATION_COMPONENT";

		componenteDeTransformacion::componenteDeTransformacion()
			: Component(COMP_NAME)
			, m_angleInDegrees(0)
			, m_angleInRadians(0)
		{}

		componenteDeTransformacion::componenteDeTransformacion(Math::Vectors position, float angleInDegrees)
			: Component(COMP_NAME)
		{
			Teleport(position);
			RotateInDegrees(angleInDegrees);
		}
		componenteDeTransformacion::~componenteDeTransformacion()
		{}

		void componenteDeTransformacion::Teleport(float x, float y)
		{
			m_position.m_x = x;
			m_position.m_y = y;
		}
		void componenteDeTransformacion::Teleport(Math::Vectors newPosition)
		{
			m_position = newPosition;
		}
		void componenteDeTransformacion::RotateInDegrees(float angle)
		{
			m_angleInDegrees = angle;
			m_angleInRadians = (angle) * (Engine::Math::PI / 180);
		}
		void componenteDeTransformacion::RotateInRadians(float angle)
		{
			m_angleInRadians = angle;
			m_angleInDegrees = angle * (180 / Engine::Math::PI);
		}
		void componenteDeTransformacion::resetShip()
		{
			m_angleInDegrees = 0;
			m_angleInRadians = 0;
		}
	}
}