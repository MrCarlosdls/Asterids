#include "ship.h"
#include <SDL2\SDL_opengl.h>
#include <cmath>
#include "mathUtilities.h"

namespace Asteroids
{
	namespace Entities
	{
		const float ANGLE_OFFSET = 90.0f;
		const float THRUST = 3.0f;
		const float MAX_SPEED = 350.0f;
		const float ROTATION_SPEED = 5.0f;
		const int RESTART_BLINK_FRAME_TIME = 30;
		const int RESPAWN_TIME = 120;
		const float BULLET_SPEED = 250;

		Ship::Ship(const std::vector<points_set> points)
			: m_ships(points)
			, m_currentIndex(0)
			, m_nRespawnTime(0)
			, m_pulse(false)
			, m_currentPulseCount(0)
			, m_totalPulseCount(30)
			, m_currentColor(Engine::Math::Vectors1(1.0f))
		{
			m_radius = 10;

			m_transforms = new Engine::Components::componenteDeTransformacion();

			AttachComponent(m_transforms);

			    m_physics = new Engine::Components::componenteRigido(
				Engine::Math::Vectors(0.0f),
				m_transforms->GetPosition(),
				1.0f,
				0.999f
			);
			AttachComponent(m_physics);
			CalculateMass();
		}

		Ship::~Ship()
		{
			
			for (auto model : m_ships)
			{
				model.clear();
			}
			m_ships.clear();
			//Entity::~Entity();
		}


		void Ship::MoveUp() const
		{
			m_physics->ApplyForce(
				Engine::Math::Vectors(THRUST),
				m_transforms->GetAngleIRadians() + Engine::Math::DegreesToRadians(ANGLE_OFFSET)
			);
		}

		void Ship::MoveRight() const
		{
			m_transforms->RotateInDegrees(m_transforms->GetAngleInDegrees() - ROTATION_SPEED);
		}

		void Ship::MoveLeft() const
		{
			m_transforms->RotateInDegrees(m_transforms->GetAngleInDegrees() + ROTATION_SPEED);
		}

		void Ship::ChangeShip()
		{
			m_currentIndex++;
			if (m_currentIndex > (m_ships.size() - 1))
			{
				m_currentIndex = 0;
			}

			CalculateMass();
		}

		void Ship::Update(double deltaTime)
		{
			m_currentSpeed = fabs(m_physics->GetSpeed());
			if (m_currentSpeed > MAX_SPEED)
			{
				m_physics->SetVelocity(
					Engine::Math::Vectors(
					(m_physics->GetVelocity().m_x / m_currentSpeed) * MAX_SPEED,
					(m_physics->GetVelocity().m_y / m_currentSpeed) * MAX_SPEED
					)
				);

				m_currentSpeed = MAX_SPEED;
			}

			Entity::Update(deltaTime);
		}

		
	void Ship::Render()
	{
		if (!m_canCollide)
		{
			if (m_nRespawnTime >= RESPAWN_TIME)
			{
				SetCollision(true);
				m_nRespawnTime = 0;
				m_pulse = false;
				m_state = EntityState::NORMAL;
				m_currentColor = Engine::Math::Vectors1(1.0f);
			}

			m_nRespawnTime++;

			if (m_pulse)
			{
				if (m_totalPulseCount > m_currentPulseCount)
				{
					m_currentPulseCount++;
					return;
				}
				if (m_nUpdates % RESTART_BLINK_FRAME_TIME == 0)
				{
					m_currentPulseCount = 0;
				}
			}
		}

		Entity::Render(GL_LINE_LOOP, m_ships[m_currentIndex], m_currentColor);
	}

		void Ship::CalculateMass()
		{
			m_physics->SetMass(m_ships[m_currentIndex].size() / 10.0f);
		}

		void Ship::Respawn()
		{
			SetCollision(false);
			m_pulse = true;
			m_currentColor = Engine::Math::Vectors1(1.0f, 0.0f, 0.0f);
			m_transforms->Teleport(0.0f, 0.0f);
			m_transforms->resetShip();
			m_physics->SetVelocity(Engine::Math::Vectors(0.f, 0.f));
			m_state = EntityState::RESPAWNING;
		}

		Bullets * Ship::Shoot() const
		{
 			float shootingAngle = m_transforms->GetAngleInDegrees() + ANGLE_OFFSET;
			float speed = m_currentSpeed + BULLET_SPEED;

			return new Bullets(m_transforms->GetPosition(), Engine::Math::Vectors(speed), shootingAngle);
		}
	}
}