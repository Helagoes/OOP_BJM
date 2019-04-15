// Name: André Harendt
// Marikelnummer: 1811126
#include "Vektor.h"
#include <iostream>
#include <utility>
using namespace std;

Vektor::Vektor(unsigned len) {
  _len = len;
  _vek = new double[_len];
  for (unsigned i = 0; i < _len; ++i) {
    _vek[i] = 0;
  }
}

// Ab hier implementieren
Vektor::Vektor(): _len(3){
	_vek = new double[_len];
	for (unsigned i = 0; i < 3; ++i)
	{
	    _vek[i] = 0;
	}
}
Vektor::~Vektor() {
	delete [] this->_vek;
}

Vektor::Vektor(const Vektor &other) {
	this->_len = other._len;
	this->_vek = new double[this->_len];
	for(unsigned i = 0; i < other._len; i++)
	{
		this->_vek[i] = other._vek[i];
	}
}

Vektor &Vektor::operator=(const Vektor &other) {
	Vektor temp(other.size());
	for(unsigned i = 0; i < other.size(); i++)
		{
			temp[i] = other.start()[i];
		}
	this->_len = other.size();
	std::swap(this->_vek, temp._vek);
	return *this;
}

Vektor operator+(Vektor left, Vektor right) {
	if(left.size() == right.size())
	{
		Vektor temp(left.size());
		for (unsigned i = 0; i < left.size(); i++)
		{
			temp.start()[i] = left.start()[i] + right.start()[i];
		}
		return temp;
	}
	else
		throw std::runtime_error("length inequality in operation requiring equality");
}

void Vektor::resize(unsigned l) {
	Vektor temp(l);
	for(unsigned i = 0; i < l; i++)
	{
		if(i < this->size())
			temp[i] = (*this)[i];
		if(i >= this->size())
			temp[i] = 0;
	}
		delete [] _vek;
		this->_vek = new double[l];
		this->_len = l;
	for(unsigned i = 0; i < l; i++)
		{
			(*this)[i] = temp[i];
		}
}
