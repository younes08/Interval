#include <cassert>
#include <iostream>
#include "ArLimiters.h"

using namespace std;
arith::ArLimiters::ArLimiters(unsigned int length, float lim1, float lim2):Array(length)
{
	this->lim1 = lim1;
	this->lim2 = lim2;
}

float arith::ArLimiters::operator[](unsigned int index)
{
	assert(index >= 0 && index < this->length);
	try
	{
		if (index < 0 || index >= this->length) throw "Overfllow or Underflow\n";
		return this->tab[index];
	}
	catch(char* e)
	{
		cout << e;
	}
}

void arith::ArLimiters::operator()(unsigned int index, float new_val)
{
	//checking the index integrity
	assert(index >= 0 && index < this->length);
	//checking the new val integrity
	assert(new_val >= this->lim1 && new_val <= this->lim2);

	try
	{
		if (index < 0 || index >= this->length) throw "Overfllow or Underflow\n";
		if (new_val < this->lim1 || new_val > this->lim2) throw "Value out of range\n";

		this->tab[index] = new_val;
	}
	catch (char* e)
	{
		cout << e;
	}
}
