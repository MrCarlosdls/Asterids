#pragma once
#include <random>

namespace Engine
{
	namespace Math
	{
		float DegreesToRadians(float angleInRadians);
		float RadiansToDegrees(float angleInDegrees);

		template<typename T>
		T RandomInRange(T min, T max)
		{
			std::random_device seeder;
			std::mt19937 engine(seeder());
			std::uniform_int_distribution<int> dist(static_cast<int>(min), static_cast<int>(max));

			return static_cast<T>(dist(engine));
		}

		inline int DieRoll()
		{
			std::random_device r;
			std::default_random_engine e1(r());
			std::uniform_int_distribution<int> uniform_dist(1, 6);
			int mean = uniform_dist(e1);
			std::seed_seq seed2{ r(), r(), r(), r(), r(), r(), r(), r() };
			std::mt19937 e2(seed2);
			std::normal_distribution<> normal_dist(mean, 2);

			return static_cast<int>(normal_dist(e2));
		}
	}
}

