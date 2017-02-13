#include "ship.h"
#include <SDL2\SDL_opengl.h>

namespace Asteroids
{
	namespace Entities
	{
		Ship::Ship(const std::vector<Engine::Math::Vectors> points)
			: m_points(points)
		{}

		void Ship::MoveUp()
		{
			Engine::Math::Vectors velocity = Engine::Math::Vectors(0, 1);
			Engine::Math::Vectors newPos =
				m_position + velocity;

			Entity::Translate(newPos);
		}

		void Ship::MoveDown()
		{
			Engine::Math::Vectors velocity = Engine::Math::Vectors(0 , -1);
			Engine::Math::Vectors newPos =
				m_position + velocity;

			Entity::Translate(newPos);
		}

		void Ship::MoveRight()
		{
			Engine::Math::Vectors velocity = Engine::Math::Vectors(1,0);
			Engine::Math::Vectors newPos =
				m_position + velocity;

			Entity::Translate(newPos);
		}
		void Ship::MoveLeft()
		{
			Engine::Math::Vectors velocity = Engine::Math::Vectors(-1,0);
			Engine::Math::Vectors newPos =
				m_position + velocity;

			Entity::Translate(newPos);
		}

		void Ship::Draw()
		{
			Entity::Draw(GL_LINE_LOOP, m_points);
		}
	}
}