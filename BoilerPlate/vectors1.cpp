#include <cmath>
#include "vectors1.h"

namespace Engine
{
	namespace Math
	{
		Vectors1::Vectors1()
			: m_x(0.0f)
			, m_y(0.0f)
			, m_z(0.0f)
			, m_length(0)
		{}
		Vectors1::Vectors1(float uniform)
			: m_x(uniform)
			, m_y(uniform)
			, m_z(uniform)
			, m_length(0)
		{}

		Vectors1::Vectors1(float _x, float _y, float _z)
			: m_x(_x)
			, m_y(_y)
			, m_z(_z)
			, m_length(0)
		{}

		Vectors1::Vectors1(const Vectors1& other)
			: m_x(other.m_x)
			, m_y(other.m_y)
			, m_z(other.m_z)
			, m_length(other.m_length)
		{}

		float Vectors1::Normalize()
		{
		
			Length();

			float inverseScale = 1.0f / m_length;
			m_x *= inverseScale;
			m_y *= inverseScale;
			m_z *= inverseScale;

			return m_length;
		}

		float Vectors1::Length()
		{
			float lenSquared = m_x * m_x + m_y * m_y + m_z * m_z;
			if (lenSquared == 0)
			{
				m_length = 0.0f;
				return m_length;
			}

			m_length = std::sqrtf(lenSquared);

			return m_length;
		}

		float Vectors1::LengthSquared() const
		{
			float lenSquared = m_x * m_x + m_y * m_y + m_z * m_z;
			if (lenSquared == 0) return 0.0f;

			return lenSquared;
		}

		void Vectors1::Scale(float scaleUnit)
		{
			m_x *= scaleUnit;
			m_y *= scaleUnit;
			m_z *= scaleUnit;
		}

		float Vectors1::SetLength(float newLength)
		{
			float oldLen = m_length;
			float lenSquared = m_x * m_x + m_y *  m_y + m_z * m_z;
			if (lenSquared == 0) return 0.0f;

			m_length = sqrtf(lenSquared);

			float inverseScale = newLength / m_length;
			m_x *= inverseScale;
			m_y *= inverseScale;
			m_z *= inverseScale;

			return oldLen;
		}
	}
}