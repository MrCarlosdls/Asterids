#pragma once

#include "escena.h"
#include "ship.h"
#include "GameObject.h"
#include "asteroide.h"

namespace Asteroids
{
	class Game
	{
	public:
		
		Game(int width, int height);
		~Game();
        void Init();
		void Update(float delta) const;
		void Render() const;
	private:
		void HandleInput() const;
		void CreatePlayer();
		void CreateAsteroids(int amount, Entities::Asteroid::AsteroidSize::Size size, Engine::Math::Vectors position = Engine::Math::Vectors::Origin) const;
		void CreateDebris(Entities::Asteroid::AsteroidSize::Size previousSize, Engine::Math::Vectors position) const;
		void CheckCollisions() const;

		Entities::Scene* m_scene;
		int m_width;
		int m_height;
		Entities::Ship* m_player;
		std::vector<Entities::Ship*> m_ships;
	};
}