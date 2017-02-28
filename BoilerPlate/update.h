#pragma once
namespace Engine
{
	namespace Core
	{
		class IUpdate
		{
		public:
			IUpdate() : m_nUpdates(0) {}
			virtual ~IUpdate() = default;

			void virtual Update(float deltaTime) { m_nUpdates++; };
	    	protected:
			
			int	m_nUpdates;
		};
	}
}