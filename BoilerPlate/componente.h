#pragma once

#include <string>
#include "update.h"
#include <iostream>

using namespace std;

namespace Engine
{
	namespace Core
	{
		class GameObject;
		class Component : IUpdate
		{
		public:
			
			explicit Component(const string& name);
			~Component();
			void Update(double deltaTime) override;

			void SetOwner(GameObject* owner) { m_owner = owner; }
			GameObject* GetOwner() const { return m_owner; }
			string GetName() const { return m_name; }
		protected:
		
			GameObject*	m_owner;
			string	    m_name;
		};
	}
}
