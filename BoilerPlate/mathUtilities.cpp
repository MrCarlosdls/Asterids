#include "mathUtilities.h"
#include "constante.h"

namespace Engine
{
	namespace Math
	{
		float DegreesToRadians(float angleInRadians)
		{
			return angleInRadians * (PI / grados);
		}
		float RadiansToDegrees(float angleInDegrees)
		{
			return angleInDegrees * (grados / PI);
		}
		
	}
}
