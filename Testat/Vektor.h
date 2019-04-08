#ifndef _VEKTOR
#define _VEKTOR

#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <utility>

class Vektor {
	private:
	int* start_adress;
	size_t length;

	public:
	Vektor();
	~Vektor();
	Vektor(const Vektor&);
	size_t size() const { return this->length; }
	Vektor& operator=(const Vektor&);
	int& get_ele(const size_t) const;
	int& set_ele(const size_t);
	void resize(unsigned);

};

Vektor& operator+(const Vektor&, const Vektor&);
#endif
