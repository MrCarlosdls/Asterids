/*#include "drawable.h"
#include <iostream>
#include <SDL2\SDL_opengl.h>

using namespace std;

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

			//traslacion
			glTranslatef(m_position.GetX(), m_position.GetY(), 1.0f);

			//rotacion 
			glRotatef(m_angulo, 0.0f, 0.0f, 1.0f);

			

			glBegin(mode);
			for (auto point : points)
			{
				glVertex2f(point.GetX(), point.GetY());
			}
			glEnd();
		}
	}
}*/