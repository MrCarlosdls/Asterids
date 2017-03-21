#include "GameObject.h"
#include <algorithm>
#include "componente.h"

namespace Engine
{
	namespace Core
	{
		GameObject::GameObject()
			: m_scene(nullptr),m_parent(nullptr)
		{
		}

		GameObject::~GameObject()
		{
			while (!m_components.empty()) delete m_components.back(), m_components.pop_back();

			while (!m_children.empty()) delete m_children.back(), m_children.pop_back();
		}
		void GameObject::AttachComponent(Component* component)
		{
			component->SetOwner(this);
			m_components.push_back(component);
		}

		void GameObject::RemoveComponent(Component* component)
		{
			m_components.erase(
				std::remove(m_components.begin(), m_components.end(), component), m_components.end()
			);

			delete component;
		}
		void GameObject::AddChild(GameObject* child)
		{
			child->m_parent = this;

			m_children.push_back(child);
		}
		void GameObject::RemoveChild(GameObject* child)
		{
			m_children.erase(
				std::remove(m_children.begin(), m_children.end(), child), m_children.end()
			);
			delete child;
		}

		void GameObject::Update(double deltaTime)
		{
			std::vector< Component* >::iterator comp = m_components.begin();
			for (; comp != m_components.end(); ++comp)
			{
				(*comp)->Update(deltaTime);
			}

			
			std::vector< GameObject* >::iterator child = m_children.begin();
			for (; child != m_children.end(); ++child)
			{
				(*child)->Update(deltaTime);
			}

			IUpdate::Update(deltaTime);
		}

		void GameObject::Render()
		{
			std::vector< GameObject* >::iterator child = m_children.begin();
			for (; child != m_children.end(); ++child)
			{
				(*child)->Render();
			}

		}
	}
}