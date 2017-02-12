#pragma once

namespace Engine
{
	namespace Math
	{
		class Vectors
		{
		public:
			/*
			* CONST
			*/
			Vectors();
			Vectors(float x, float y);

			/*
			* PUBLIC FUNCTIONS
			*/
			float Length();
			float SquaredLength();
			const float GetX();
			const float GetY();

			/*
			* OPERATORS
			*/
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
