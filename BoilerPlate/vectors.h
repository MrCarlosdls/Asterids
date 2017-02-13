#pragma once

namespace Engine
{
	namespace Math
	{
		class Vectors
		{
		public:
		
			Vectors();
			Vectors(float x, float y);

		
			float Length();
			float SquaredLength();
			const float GetX();
			const float GetY();

			///OPERADORES
			Vectors& operator=(const Vectors& rhs);
			Vectors& operator+=(const Vectors& rhs);
			Vectors& operator-=(const Vectors& rhs);
			Vectors& operator*=(const Vectors& rhs);
			Vectors& operator/=(const Vectors& rhs);
			Vectors operator+(const Vectors& rhs);
			Vectors operator-(const Vectors& rhs);
			Vectors operator-();
			Vectors operator*(const Vectors& rhs);
			Vectors operator/(const Vectors& rhs);
			bool operator==(const Vectors& rhs);
			bool operator!=(const Vectors& rhs);
			friend Vectors operator*(float scaleUnit, const Vectors& rhs);
			friend Vectors operator*(const Vectors& lhs, float scaleUnit);

		private:
			float m_x;
			float m_y;
			float m_length;
		};
	}
}
