#include "intvector.h"
#include <cstdlib>
#include <iostream>

int& intvector::at(size_t idx)
	{
		if(idx < this->size())
			return (this->start_adr)[idx];
		else
			throw std::runtime_error("index out of range");
	}
void intvector::out() const
{
	for(size_t i = 0; i < this->len; i++)
	{
		std::cout << i << "tes Element des Vectors: " << (this->start_adr)[i] << std::endl;
	}
}
