#include <cassert>
#include <iostream>
#include "Array.h"

using namespace std;
using namespace arith;

arith::Array::Array(unsigned int length)
{
	this->length = length;
	this->tab = new float[length];
	//init tab with zeros
	for (int index = 0; index < length; this->tab[index++] = 0);

	assert(this->tab);
}

arith::Array::Array(Array& Ar)
{
	this->length = Ar.length;

	//clear the old array if existing 
	if (this->tab)
	{
		delete[] this->tab;
		this->tab = 0;
	}
	//reallocating new space
	this->tab = new float[Ar.length];

	//filling the table with the data
	for (int counter = 0; counter < Ar.length; counter++)
		this->tab[counter] = Ar.tab[counter];
}

Array& arith::Array::operator=(const Array& Ar)
{
	//checking if it's the same obj
	if (this != &Ar)
	{
		this->length = Ar.length;

		//clear the old array if existing 
		if (this->tab)
		{
			delete[] this->tab;
			this->tab = 0;
		}
		//reallocating new space
		this->tab = new float[Ar.length];

		//filling the table with the data
		for (int counter = 0; counter < Ar.length; counter++)
			this->tab[counter] = Ar.tab[counter];
	}

	return *this;
}

void arith::Array::print() const
{
	for (int index = 0; index < this->length; cout << this->tab[index++]);
	cout << endl;
}

float& arith::Array::operator[](unsigned int index)
{
	assert(index >= 0 && index < this->length);
	try
	{
		if (index < 0 || index >= this->length) throw "Overflow or Underflow\n";
		return this->tab[index];
	}
	catch (char* e)
	{
		cout << e;
	}
}

arith::Array::~Array()
{
	if (this->tab)
	{
		delete[] this->tab;
		this->tab = nullptr;
	}
}
