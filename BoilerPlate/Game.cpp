#include "Game.h"
#include <iostream>
#include "config.h"
#include "manager.h"
#include "asteroide.h"
#include <algorithm>

namespace Asteroids
{
	Game::Game(int width, int height)
		: m_scene(nullptr)
		, m_width(width)
		, m_height(height)
		, m_player(nullptr)
	{}

	Game::~Game()
	{
		delete m_scene;

		m_bullets.clear();
	}

	void Game::Init()
	{
		m_scene = new Entities::Scene(
			Engine::Math::Vectors1(0, 0, 0),
			m_width,
			m_height
		);
		CreatePlayer();
		CreateAsteroids(10, Entities::Asteroid::AsteroidSize::BIG);
	}

	void Game::Update(double deltaTime)
	{
		HandleInput();
		m_scene->Update(deltaTime);
		CheckCollisions();
		limpiarBullets();
	}

	void Game::Render() const
	{
		m_scene->Render();
	}

	void Game::HandleInput()
	{
		if (Engine::Input::InputManager::Instance().IsKeyPressed('w'))
		{
			m_player->MoveUp();
		}

		if (Engine::Input::InputManager::Instance().IsKeyPressed('a'))
		{
			m_player->MoveLeft();
		}

		if (Engine::Input::InputManager::Instance().IsKeyPressed('d'))
		{
			m_player->MoveRight();
		}
		if (Engine::Input::InputManager::Instance().IsKeyReleased('p'))
		{
			m_player->ChangeShip();
		}
		if (Engine::Input::InputManager::Instance().IsKeyReleased(' '))
		{
			if (m_player->IsRespawning()) return;
			Entities::Bullets* bala = m_player->Shoot();
			m_bullets.push_back(bala);
			m_scene->AddChild(bala);
		}
	}

	void Game::CreatePlayer()
	{
		utilities::Configuration config;
		m_player = new Entities::Ship(config.LoadModels());

		m_scene->AddChild(m_player);
	}

	void Game::CreateAsteroids(int amount, Entities::Asteroid::AsteroidSize::Size size, Engine::Math::Vectors position) const
	{
		for (int i = 0; i < amount; ++i)
		{
			Entities::Asteroid* pAsteroid =
				new Entities::Asteroid(size,position);

			m_scene->AddChild(pAsteroid);

			if (position == Engine::Math::Vectors::Origin)
			{
				pAsteroid->ApplyRandomTranslation();
			}
		}
	}
	void Game::CreateDebris(Entities::Asteroid* asteroide) const
	{
		Entities::Asteroid::AsteroidSize::Size currentSize = asteroide->GetSize();
		if (currentSize == Entities::Asteroid::AsteroidSize::BIG)
		{
			CreateAsteroids(2, Entities::Asteroid::AsteroidSize::MEDIUM, asteroide->GetPosition());
		}

		if (currentSize == Entities::Asteroid::AsteroidSize::MEDIUM)
		{
			CreateAsteroids(2, Entities::Asteroid::AsteroidSize::SMALL, asteroide->GetPosition());
		}
		m_scene->RemoveChild(asteroide);
	}

	void Game::CheckCollisions()
	{
		if (!m_player->CanCollide())
			return;

		for (auto a : m_scene->GetChildren())
		{
			Entities::Asteroid* asteroide = dynamic_cast<Entities::Asteroid*>(a);
			if (asteroide)
			{
				inpactoConJugador(asteroide);
				inpactoConBullet(asteroide);
			}
		}
	}
	void Game::limpiarBullets()
	{
		if (m_bullets.size() == 0) return;

		auto iter = std::find_if(m_bullets.begin(), m_bullets.end(),
			[&](Entities::Bullets* bullet) { return bullet->ShouldBeDeleted() || bullet->IsColliding(); });
		if (iter != m_bullets.end())
		{
			deleteBullet(*iter);
		}

	}
	void Game::inpactoConJugador(Entities::Asteroid* asteroide)const
	{
		if (m_player->IsColliding(asteroide))
		{
			CreateDebris(asteroide);
			m_player->Respawn();
		}
	}

	void Game::inpactoConBullet(Entities::Asteroid* asteroide)
	{
		for (auto bullet : m_bullets)
		{
			if (bullet->IsColliding(asteroide))
			{
				CreateDebris(asteroide);
			}
		}
	}
	void Game::deleteBullet(Entities::Bullets* bala)
	{
		m_scene->RemoveChild(bala);


		auto bulletResult = find(m_bullets.begin(), m_bullets.end(), bala);
		if (m_bullets.size() > 0 && bulletResult != m_bullets.end())
		{
			m_bullets.erase(bulletResult);
		}
	}
}


	

