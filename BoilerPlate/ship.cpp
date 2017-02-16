#include "ship.h"
#include <SDL2\SDL_opengl.h>
#include <cmath>
#include "constante.h"


using namespace std;

namespace Asteroids
{
	namespace Entities
	{
		
		const float M_ANGULO_INICIAL = 90.0f;
		Ship::Ship(const std::vector<Engine::Math::Vectors> points)
			: m_points(points)
			//,M_ANGULO_INICIAL
		{


			m_angulo = 0.0f;
			m_anguloEnRadianes = M_ANGULO_INICIAL * (PI / 180);
		
		
		
		}
	

		void Ship::MoveUp()
		{
			//Engine::Math::Vectors velocity = Engine::Math::Vectors(0, 3);

			Engine::Math::Vectors velocity
			(

				10 * cosf(m_anguloEnRadianes),
				10 * sinf(m_anguloEnRadianes)
			);

			Engine::Math::Vectors newPos =
				m_position + velocity;

			Entity::Translate(newPos);
		}

		void Ship::MoveDown()
		{
			Engine::Math::Vectors velocity = Engine::Math::Vectors(0 , -3);
			Engine::Math::Vectors newPos =
				m_position + velocity;

			Entity::Translate(newPos);
		}

		void Ship::MoveRight()
		{
			/*Engine::Math::Vectors velocity = Engine::Math::Vectors(3,0);
			Engine::Math::Vectors newPos =
				m_position + velocity;

			Entity::Translate(newPos);*/


			m_angulo -= 5.0f;
			m_anguloEnRadianes = (m_angulo + M_ANGULO_INICIAL) * (PI / 180);


		}
		void Ship::MoveLeft()
		{
			/*Engine::Math::Vectors velocity = Engine::Math::Vectors(-3,0);
			Engine::Math::Vectors newPos =
				m_position + velocity;

			Entity::Translate(newPos);
			*/


			m_angulo += 5.0f;
			m_anguloEnRadianes = (m_angulo + M_ANGULO_INICIAL) * (PI / 180);

		}
		void Ship::Draw()
		{
			Entity::Draw(GL_LINE_LOOP, m_points);


			/*if (x < 0) {
				x += renderer->ResolutionX;
			}

			else if (x >= renderer->ResolutionX) {
				x -= renderer->ResolutionX;
			}

			else if (y < 0) {
				y += renderer->ResolutionY;
			}
			else if (y >= renderer->ResolutionY) {
				y -= renderer->ResolutionY;
			}*/

		}
	}
}