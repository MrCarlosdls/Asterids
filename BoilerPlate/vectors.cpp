#include "vectors.h"
#include <cmath>

using namespace std;

namespace Engine
{
	namespace Math
	{
		Vectors Vectors::Origin = Vectors();

		Vectors::Vectors()
			: m_x(0.0f)
			, m_y(0.0f)
			, m_length(0.0f)
		{}

		Vectors::Vectors(float x, float y)
			: m_x(x)
			, m_y(y)
			, m_length(0)
		{
			Length();
		}

		Vectors::Vectors(float uniform)
			: m_x(uniform)
			, m_y(uniform)
			, m_length(0)

		{
			Length();
		}
		
		 float Vectors::GetX()
		{
			return m_x;
		}

		 float Vectors::GetY()
		{
			return m_y;
		}
		

		float Vectors::Length() const
		{
			return sqrt(m_x * m_x + m_y * m_y);
		}

		float Vectors::SquaredLength() const
		{
			return m_x * m_x + m_y * m_y;
		}

		float Vectors::Normalize()
		{
			Length();
			float escalaInvertida = 1.0f / m_length;
			m_x *= escalaInvertida;
			m_y *= escalaInvertida;

			return m_length;

		}

		///OPERADORES
		Vectors& Vectors::operator=(const Vectors& rhs)
		{
		
			if (this == &rhs)
			{
				return *this;
			}

			m_x = rhs.m_x;
			m_y = rhs.m_y;

			return *this;
		}

		Vectors& Vectors::operator+=(const Vectors& rhs)
		{
			m_x = m_x + rhs.m_x;
			m_y = m_y + rhs.m_y;

			return *this;
		}

		Vectors& Vectors::operator-=(const Vectors& rhs)
		{
			m_x = m_x - rhs.m_x;
			m_y = m_y - rhs.m_y;

			return *this;
		}

		Vectors& Vectors::operator*=(const Vectors& rhs)
		{
			m_x = m_x * rhs.m_x;
			m_y = m_y * rhs.m_y;

			return *this;
		}

		Vectors& Vectors::operator/=(const Vectors& rhs)
		{
			m_x = m_x / rhs.m_x;
			m_y = m_y / rhs.m_y;

			return *this;
		}

		Vectors Vectors::operator+(const Vectors& rhs)
		{
			Vectors sum;

			sum.m_x = m_x + rhs.m_x;
			sum.m_y = m_y + rhs.m_y;

			return sum;
		}

		Vectors Vectors::operator-(const Vectors& rhs)
		{
			Vectors sub;
			sub.m_x = m_x - rhs.m_x;
			sub.m_y = m_y - rhs.m_y;

			return sub;
		}

		Vectors Vectors::operator-()
		{
			return Vectors(-m_x, -m_y);
		}

		Vectors Vectors::operator*(const Vectors& rhs)
		{
			Vectors scaled;

			scaled.m_y = m_y * rhs.m_y;
			scaled.m_x = m_x * rhs.m_x;

			return scaled;
		}

		Vectors Vectors::operator/(const Vectors& rhs)
		{
			Vectors inverseScaled;

			inverseScaled.m_x = m_x / rhs.m_x;
			inverseScaled.m_y = m_y / rhs.m_y;

			return inverseScaled;
		}

		bool Vectors::operator==(const Vectors& rhs)
		{
			return
				m_x == rhs.m_x &&
				m_y == rhs.m_y;
		}

		bool Vectors::operator!=(const Vectors& rhs)
		{
			return
				m_x != rhs.m_x ||
				m_y != rhs.m_y;
		}

		Vectors operator*(float scaleUnit, const Vectors& rhs)
		{
			Vectors scaled;
			scaled.m_x = scaleUnit * rhs.m_x;
			scaled.m_y = scaleUnit * rhs.m_y;

			return scaled;
		}

		Vectors operator*(const Vectors& lhs, float scaleUnit)
		{
			Vectors scaled;
			scaled.m_x = scaleUnit * lhs.m_x;
			scaled.m_y = scaleUnit * lhs.m_y;

			return scaled;
		}
	}
}