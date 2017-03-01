#include "asteroide.h"
#include <SDL2/SDL_opengl.h>
#include "constante.h"
#include "cuerpoRigido.h"
#include "componenteDeTransformacion.h"
#include "mathUtilities.h"
#include "escena.h"

namespace Asteroids
{
	namespace Entities
	{
		const int NUM_POINTS = 16;
		const float MIN_SIZE = 25.0f;
		const float MAX_SIZE = 45.0f;
		const float ROTATION_SPEED = 120.0f;

		Asteroid::Asteroid(AsteroidSize::Size size, Engine::Math::Vectors position)
			: m_size(size)
		{
			if (size == AsteroidSize::BIG) m_radius = 40.f;
			if (size == AsteroidSize::MEDIUM) m_radius = 20.f;
			if (size == AsteroidSize::SMALL) m_radius = 10.f;

			m_sizeFactor = static_cast<int>(size) + 1;

		
			m_transforms = new Engine::Components::componenteDeTransformacion();
			m_transforms->Teleport(position);

			
			AttachComponent(m_transforms);

			m_physics = new Engine::Components::componenteRigido(
				Engine::Math::Vectors(0.0f), 
				m_transforms->GetPosition(),
				1.0f,
				1.0f 
			);

			AttachComponent(m_physics);
			Generate();

			ApplyRandomImpulse();
		}

		void Asteroid::Update(double deltaTime)
		{
			float angle = m_transforms->GetAngleInDegrees() + ROTATION_SPEED * static_cast<float>(deltaTime);
			m_transforms->RotateInDegrees(angle);

			Entity::Update(deltaTime);
		}

		void Asteroid::Render()
		{
			Entity::Render(GL_LINE_LOOP, m_points);
		}

		void Asteroid::Generate()
		{
			float min = MIN_SIZE / m_sizeFactor;
			float max = MAX_SIZE / m_sizeFactor;

			for (int idx = 0; idx < NUM_POINTS; ++idx)
			{
				const float radians = (idx / static_cast<float>(NUM_POINTS)) * 2.0f * Engine::Math::PI;
				const float randDist = Engine::Math::RandomInRange<float>(min, max);

				m_points.push_back(Engine::Math::Vectors(sinf(radians) * randDist, cosf(radians) * randDist));
			}
		}

		void Asteroid::ApplyRandomImpulse() const 
		{
			float x = Engine::Math::RandomInRange<float>(-150.0f, 150.0f);
			float y = Engine::Math::RandomInRange<float>(-150.0f, 150.0f);

			m_physics->ApplyForce(
				Engine::Math::Vectors(x, y) + static_cast<int>(m_sizeFactor),
				m_transforms->GetAngleIRadians()
			);
		}

		void Asteroid::ApplyRandomTranslation() const
		{
			Scene* scene = dynamic_cast<Scene*>(GetParent());
			if (!scene) return;

			float dimensions[2];

			dimensions[0] = (scene->GetWidth() / 2.0f);
			dimensions[1] = (scene->GetHeight() / 2.0f);

			const int sideAxis = Engine::Math::DieRoll() & 1;
			const float sideDir = (Engine::Math::DieRoll() & 1) ? 1.0f : -1.0f;

			const int otherSideAxis = (sideAxis + 1) & 1;

			float point[2];
			point[sideAxis] = sideDir * Engine::Math::RandomInRange<float>(dimensions[sideAxis] * -1.0f, dimensions[sideAxis]);
			point[otherSideAxis] = Engine::Math::RandomInRange<float>(dimensions[otherSideAxis] * -1.0f, dimensions[otherSideAxis]);

			m_transforms->Teleport(point[0], point[1]);
		}
	}
}
