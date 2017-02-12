#include "drawable.h"
#include <SDL2\SDL_opengl.h>

namespace Engine
{
	namespace Graphics
	{
		void Drawable2D::Translate(Math::Vectors position)
		{
			m_position = position;
		}

		void Drawable2D::Draw(unsigned int mode, std::vector<Math::Vectors> points)
		{
			
			glLoadIdentity();

			
			glTranslatef(m_position.GetX(), m_position.GetY(), 0.0f);

			
			glBegin(mode);
			for (auto point : points)
			{
				glVertex2f(point.GetX(), point.GetY());
			}
			glEnd();
		}
	}
}