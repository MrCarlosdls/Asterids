#pragma once

#include "escena.h"
#include "ship.h"
#include "GameObject.h"
#include "asteroide.h"
#include "bullet.h"
#include <list>

using namespace std;

namespace Asteroids
{
	class Game
	{
	public:
		Game(int width, int height);
		~Game();
        void Init();
		void Update(double deltaTime) ;
		void Render() const;
	
	private:
		void HandleInput();
		void CreatePlayer();
		void CreateAsteroids(int amount, Entities::Asteroid::AsteroidSize::Size size, Engine::Math::Vectors position = Engine::Math::Vectors::Origin) const;
		void CreateDebris(Entities::Asteroid* asteroide)const;
		void CheckCollisions() ;
		void limpiarBullets();
		void inpactoConJugador(Entities::Asteroid* asteroide)const;
		void inpactoConBullet(Entities::Asteroid* asteroide);
		void deleteBullet(Entities::Bullets* bala);

		
		Entities::Scene* m_scene;
		int m_width;
		int m_height;
		Entities::Ship* m_player;
		list<Entities::Bullets*> m_bullets;
	   
	};
}