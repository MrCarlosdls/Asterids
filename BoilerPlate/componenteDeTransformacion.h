#pragma once
#include "vectors.h"
#include "vectors1.h"
#include "componente.h"
#include "constante.h"

namespace Engine
{
	namespace Components
	{
		class componenteDeTransformacion : public Core::Component
		{
		public:
			
			componenteDeTransformacion();
			componenteDeTransformacion(Math::Vectors position, float angleInDegrees);
			~componenteDeTransformacion();
			void Teleport(float x, float y);
			void Teleport(Math::Vectors newPosition);
			void RotateInDegrees(float angle);
			void RotateInRadians(float angle);
			void resetShip();

			Math::Vectors GetPosition() const { return m_position; }
			float GetAngleInDegrees() const { return m_angleInDegrees; }
			float GetAngleIRadians() const { return m_angleInRadians; }
		protected:
		
			Math::Vectors m_position;
			Math::Vectors1 m_rotation;
			float m_angleInDegrees;
			float m_angleInRadians;
		};
	}
}