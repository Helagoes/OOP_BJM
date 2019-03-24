#include "at.h"
#include <stdexcept>

int &at(int *vec, int len, int i)
{
	if(i > len-1 || i < 0)
	{
		throw std::runtime_error("index overflow");
	}
	else
	{
		return vec[i];
	}
}
