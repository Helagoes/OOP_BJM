#include "Vektor.h"

Vektor::Vektor(){
	this->start_adress = new int[3];
	this->length = 3;
	for(size_t i = 0; i < 3; i++)
		this->get_ele(i) = 0;
}

Vektor::~Vektor(){
	delete [] this->start_adress;
}

Vektor::Vektor(const Vektor& ref)
{
	this->start_adress = new int[ref.size()];
	this->length = ref.size();
	for(size_t i = 0; i < ref.size(); i++)
	{
		this->start_adress[i] = ref.start_adress[i];
	}
}

Vektor& Vektor::operator=(const Vektor& ref)
{
	Vektor temp(ref);
	std::swap(this->start_adress, temp.start_adress);
	std::swap(this->length, temp.length);
	return *this;
}

int& Vektor::get_ele(const size_t idx) const
{
	return (this->start_adress)[idx];
}

int& Vektor::set_ele(const size_t idx)
{
	return (this->start_adress)[idx];
}

Vektor& operator+(const Vektor& a, const Vektor& b)
{
	if(a.size() == b.size())
	{
		Vektor temp(a);
		for(size_t i = 0; i < a.size(); i++)
		{
			temp.get_ele(i) = a.get_ele(i) + b.get_ele(i);
		}
		return temp;
	}
	else
		throw std::runtime_error("vector length not equal, therefore cannot complete addition");
}

void Vektor::resize(unsigned l)
{
	if(l == this->size())
		return;
	else
	{
		Vektor temp(*this);
		this->start_adress = new int[l];
		for(size_t i = 0; i < l; i++)
		{
			if(i <= this->size()) //kopierbereich
				this->get_ele(i) = temp.get_ele(i);
			else //initialisieren
				this->get_ele(i) = 0;
		}
		this->length = l;
		return;
	}

}
