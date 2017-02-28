#pragma once


#include "vectors1.h"
#include "GameObject.h"

namespace Asteroids
{
	namespace Entities
	{
		class Scene : public Engine::Core::GameObject
		{
		public:
			Scene(Engine::Math::Vectors1 background, int width, int height);

			void Render() override;

			int GetWidth() const { return m_width; }
			int GetHeight() const { return m_height; }
		private:
			Engine::Math::Vectors1 m_background;
			int m_width;
			int m_height;
		};
	}
}