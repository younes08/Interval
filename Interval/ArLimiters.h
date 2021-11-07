#pragma once
#include "Array.h"

namespace arith
{
	class ArLimiters :
		public Array
	{
		private:
			float lim1;
			float lim2;
		
		public:
			ArLimiters(unsigned int, float, float);
			float operator [](unsigned int);
			void operator ()(unsigned int, float);
	};
}

