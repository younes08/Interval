#pragma once

namespace arith
{
	class Array
	{
		protected:
			unsigned int length;
			float* tab;

		private:
			float& operator [](unsigned int);
		
		public:
			Array(unsigned int);

			Array(Array&);
			Array& operator =(const Array&);
			void print() const;

			~Array();
	};
}

