#include "escena.h"
#include <SDL2/SDL_opengl.h>

namespace Asteroids
{
	namespace Entities
	{
		Scene::Scene(Engine::Math::Vectors1 background, int width, int height)
			: m_background(background)
			, m_width(width)
			, m_height(height)
		{}
		void Scene::Render()
		{
			glClearColor(
				m_background.m_x,
				m_background.m_y,
				m_background.m_z,
				1.0f);

			glClear(GL_COLOR_BUFFER_BIT);

			GameObject::Render();
		}
	}
}