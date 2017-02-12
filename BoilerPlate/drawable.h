#pragma once
#include <vector>
#include "Vectors.h"

namespace Engine
{
	namespace Graphics
	{
		class Drawable2D
		{
		public:
			virtual void Translate(Math::Vectors position);
			virtual void Draw(unsigned int mode, std::vector<Math::Vectors> points);
		protected:
			Engine::Math::Vectors m_position;
		};
	}
}

