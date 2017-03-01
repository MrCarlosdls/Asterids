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

			void virtual Update(double deltaTime) { m_nUpdates++; };
	    	protected:
			
			int	m_nUpdates;
		};
	}
}