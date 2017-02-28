#pragma once
#include <vector>
#include "update.h"
#include "render.h"
#include "unique.h"
#include <iostream>

namespace Engine
{
	namespace Core
	{
		class Component;
		class Scene;
		class GameObject : public IUpdate, public IRender, public UniqueID
		{
		public:
			GameObject();
			~GameObject();

			
			void AttachComponent(Component*);
			void RemoveComponent(Component*);
			void AddChild(GameObject*);
			void RemoveChild(GameObject*);
			void Update(float deltaTime) override;
			void Render() override;

			
			std::vector<Component*>GetComponents() const 
			{ 
				return m_components; 
			}
			std::vector<GameObject*> GetChildren() const 
			{
				return m_children;
			}
			GameObject* GetParent() const 
			{
				return m_parent; 
			}

			template<typename T>
			T* GetComponent()
			{
				std::vector< Component* >::iterator comp = m_components.begin();
				for (; comp != m_components.end(); ++comp)
				{
					T* theComponent = dynamic_cast<T*>(*comp);
					if (theComponent)
					{
						return theComponent;
					}
				}

				return nullptr;
			}
		protected:
		
			std::vector<Component*>	m_components;
			Scene* m_scene;
			std::vector<GameObject*> m_children;
			GameObject* m_parent;
		};
	}
}