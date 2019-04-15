// Name: André Harendt
// Marikelnummer: 1811126
#include "Vektor.h"
#include <iostream>
using namespace std;

Vektor::Vektor(unsigned len) {
  _len = len;
  _vek = new double[_len];
  for (unsigned i = 0; i < _len; ++i) {
    _vek[i] = 0;
  }
}

// Ab hier implementieren
Vektor::Vektor(): _len(3) {
	_vek = new double[_len];
	for (unsigned i = 0; i < _len; ++i)
	{
	    _vek[i] = 0;
	}
}
Vektor::~Vektor() {
	delete [] _vek;
}

Vektor::Vektor(const Vektor &other) {
}

Vektor &Vektor::operator=(const Vektor &other) {
}

Vektor operator+(Vektor left, Vektor right) {
}

void Vektor::resize(unsigned l) {
}
