#include "componente.h"
#include <iostream>

using namespace std;

namespace Engine
{
	namespace Core
	{
		Component::Component(const string& name)
			: m_name(name)
		{}

		Component::~Component()
		{
			m_owner = nullptr;
		}

		void Component::Update(float deltaTime)
		{
			IUpdate::Update(deltaTime);
		}
	}
}