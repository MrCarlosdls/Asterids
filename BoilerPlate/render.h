#pragma once
namespace Engine
{
	namespace Core
	{
		class IRender
		{
		public:
			virtual ~IRender() = default;
			
			void virtual Render() = 0;
		};
	}
}