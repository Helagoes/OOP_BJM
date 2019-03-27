#include <cstdlib>
#include <iostream>
#include <utility>
#include "IntVector.h"

int& IntVector::at(size_t idx)
	{
		if(idx < this->size())
			return (this->start_adr)[idx];
		else
			throw std::runtime_error("index out of range");
	}
void IntVector::out() const
{
	for(size_t i = 0; i < this->len; i++)
	{
		std::cout << i << "tes Element des Vectors: " << (this->start_adr)[i] << std::endl;
	}
}
IntVector &IntVector::operator=(const IntVector& ref)
{
	int* temp = this->start_adr;
	this->start_adr = new int[ref.size()];
	this->len = ref.size();
	delete [] temp;
		for(size_t i = 0; i < this->size(); i++)
		{
			(this->start_adr)[i] = (ref.start_adr)[i];
		}
	return *this;

}
