#include "entity.h"
#include <SDL2/SDL_opengl.h>
#include "escena.h"
#include "cuerpoRigido.h"
#include "componenteDeTransformacion.h"

namespace Asteroids
{
	namespace Entities
	{
		inline float wrap(float axis, float min, float max)
		{
			if (axis < min)
			{
				return max - (min - axis);
			}

			if (axis > max)
			{
				return min + (axis - max);
			}

			return axis;
		}

		Entity::Entity()
			: m_transforms(nullptr)
			, m_physics(nullptr)
			, m_halfWidth(0)
			, m_halfHeight(0)
			,m_radius(0)
			,m_canCollide(false)
			,m_state(EntityState::NORMAL)
		{}

		void Entity::Update(double deltaTime)
		{
			if (!GetParent()) return;

			Scene* scene = dynamic_cast<Scene*>(GetParent());
			if (!scene) return;

			m_halfWidth = (scene->GetWidth() / 2.0f);
			m_halfHeight = (scene->GetHeight() / 2.0f);

			if (!m_physics || !m_transforms) return;

			Engine::Math::Vectors newPos(
				m_transforms->GetPosition().m_x + (m_physics->GetVelocity().m_x *static_cast<float>(deltaTime)),
				m_transforms->GetPosition().m_y + (m_physics->GetVelocity().m_y * static_cast<float>(deltaTime))
			);

			float worldMinX = -m_halfWidth;
			float worldMaxX = m_halfWidth;

			float worldMinY = -m_halfHeight;
			float worldMaxY = m_halfHeight;

			float x = wrap(newPos.m_x, worldMinX, worldMaxX);
			float y = wrap(newPos.m_y, worldMinY, worldMaxY);

			m_transforms->Teleport(x, y);

			Test->Update(m_transforms->GetPosition().m_x,m_transforms->GetPosition().m_y);

			GameObject::Update(deltaTime);
		}

		void Entity::Render(unsigned int mode, std::vector<Engine::Math::Vectors> points, Engine::Math::Vectors1 color)
		{
			Engine::Components::componenteDeTransformacion* transforms = GetComponent<Engine::Components::componenteDeTransformacion>();
			if (!transforms) return;

			glLoadIdentity();
			glTranslatef(transforms->GetPosition().m_x, transforms->GetPosition().m_y, 0.0f);
			glRotatef(transforms->GetAngleInDegrees(), 0.0f, 0.0f, 1.0f);
			glColor3f(color.m_x, color.m_y, color.m_z);
			glBegin(mode);

			for (auto point : points)
			{
				glVertex2f(point.m_x, point.m_y);
			}
			glEnd();

			glLoadIdentity();
			glBegin(mode);
			glColor3f(color.m_x, color.m_y, color.m_z);
			glVertex2f(Test->GetMinX(), Test->GetMinY());
			glVertex2f(Test->GetMaxX(), Test->GetMinY());
			glVertex2f(Test->GetMaxX(), Test->GetMaxY());
			glVertex2f(Test->GetMinX(), Test->GetMaxY());
			glEnd();

			

			GameObject::Render();
		}
		bool Entity::IsColliding(Entity* param)
		{
			if (CanCollide())
			{
				return Test->isIntersecting(param->Test);
			}
			return false;

		}

		
		/*bool Entity::IsColliding(Entity * rhs) 
		{
			Engine::Components::componenteDeTransformacion* t_rhs =
				rhs->GetComponent<Engine::Components::componenteDeTransformacion>();

			if (!rhs) 
				return false;
			if (!t_rhs)
				return false;

			float x = m_transforms->GetPosition().m_x - t_rhs->GetPosition().m_x;
			float y = m_transforms->GetPosition().m_y - t_rhs->GetPosition().m_y;

			float radii = m_radius + rhs->m_radius;
			float distSquared = x * x + y * y;

	        bool intersectos = radii * radii >= distSquared;

			if (intersectos)
			{
				m_state = EntityState::COLLIDED;
				return intersectos;
			}
		}*/
	}
}
