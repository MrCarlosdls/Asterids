#include "bullet.h"
#include <SDL2/SDL_opengl.h>
#include "mathUtilities.h"

using namespace std;

namespace Asteroids
{
	namespace Entities
	{
		/*const float MAX_SPEED = 500.0f;
		const float Points = 4.0f;
		const float tamanio = 4.0f;*/

		Bullets::Bullets(Engine::Math::Vectors position,
			Engine::Math::Vectors velocidad, float angulo,
			unsigned int maxFrameLifeTime)
			:m_framelife(0), m_maxframelife(maxFrameLifeTime)
		{
			//Attached components of entity
			
			

			m_radius = 1.0f;
			m_width = m_transforms->GetPosition().m_x;
			m_height = m_transforms->GetPosition().m_y;
			m_transforms = new Engine::Components::componenteDeTransformacion();
			m_transforms->Teleport(position);
			AttachComponent(m_transforms);

			m_physics = new Engine::Components::componenteRigido(Engine::Math::Vectors(0.0f), m_transforms->GetPosition());
			m_physics->ApplyForce(velocidad, Engine::Math::DegreesToRadians(angulo));
			AttachComponent(m_physics);

		}
			void Bullets::Update(double deltaTime)
			{
				if (m_framelife > m_maxframelife)
				{
					m_state = EntityState::DELETED;
					return;
				}

				m_framelife++;
				Entity::Update(deltaTime);
			}

			void Bullets::Render()
			{
				glLoadIdentity();

				glPointSize(2.0f);

				glEnable(GL_POINT_SMOOTH);

				glBegin(GL_POINTS);

				glVertex2f(m_transforms->GetPosition().m_x, m_transforms->GetPosition().m_y);

				glEnd();

			}







		}
	}
