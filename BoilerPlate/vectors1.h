#pragma once

namespace Engine
{
	namespace Math
	{
		class Vectors1
		{
		public:

			explicit Vectors1();
			explicit Vectors1(float uniform);
			explicit Vectors1(float x, float y, float z);
			Vectors1(const Vectors1& other);

			float Normalize();
			float Length();
			float LengthSquared() const;
			void Scale(float scaleUnit);
			float SetLength(float newLength);

			float m_x;
			float m_y;
			float m_z;
			float m_length;
		};
	}
}