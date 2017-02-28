#include "Game.h"
#include <iostream>
#include "config.h"
#include "manager.h"
#include "asteroide.h"

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

		m_ships.clear();
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

	void Game::Update(float delta) const
	{
		HandleInput();
		m_scene->Update(delta);
		CheckCollisions();
	}

	void Game::Render() const
	{
		m_scene->Render();
	}

	void Game::HandleInput() const
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
				new Entities::Asteroid(Entities::Asteroid::AsteroidSize::BIG);

			m_scene->AddChild(pAsteroid);

			if (position == Engine::Math::Vectors::Origin)
			{
				pAsteroid->ApplyRandomTranslation();
			}
		}
	}
			void Game::CreateDebris(Entities::Asteroid::AsteroidSize::Size previousSize, Engine::Math::Vectors position) const
			{
				if (previousSize == Entities::Asteroid::AsteroidSize::BIG)
				{
					CreateAsteroids(2, Entities::Asteroid::AsteroidSize::MEDIUM, position);
				}

				if (previousSize == Entities::Asteroid::AsteroidSize::MEDIUM)
				{
					CreateAsteroids(2, Entities::Asteroid::AsteroidSize::SMALL, position);
				}
			}

			void Game::CheckCollisions() const
			{
				if (!m_player->CanCollide()) return;

				for (auto a : m_scene->GetChildren())
				{
					Entities::Asteroid* pAsteroid = dynamic_cast<Entities::Asteroid*>(a);
					if (pAsteroid)
					{
						if (m_player->IsColliding(pAsteroid))
						{
							Entities::Asteroid::AsteroidSize::Size currentSize = pAsteroid->GetSize();
							m_scene->RemoveChild(a);
							CreateDebris(currentSize, m_player->GetPosition());
							m_player->Respawn();
						}
					}
				}
		}
	}

