#pragma once
namespace Engine
{
	namespace Core
	{
		class UniqueID
		{
		public:
		
			UniqueID();
			UniqueID(const UniqueID& orig);

			UniqueID& operator=(const UniqueID& orig);

			int id;
		protected:
			static int nextID;
		};
	}
}
