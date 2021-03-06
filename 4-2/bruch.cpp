#include "bruch.h"
#include <cstdlib>
#include <iostream>
#include <utility>

void Bruch::normalize()
{
	//normalize sign
	if(this->nenner < 0)
	{
		this->zaehler = -(this->zaehler);
		this->nenner = -(this->nenner);
	}

	//get absolute values of Bruch
	int abs_zaehler = 0;
	if(this->zaehler < 0)
		abs_zaehler = -(this->zaehler);
	else
		abs_zaehler = this->zaehler;

	//compute biggest common divider
	int div = ggt(abs_zaehler, this->nenner);

	this->zaehler /= div;
	this->nenner /= div;

	return;

}
int Bruch::ggt(int a, int b) const
{
	while (a != 0)
	{
		std::swap(a, b);
		a %= b;
	}
	return b;
}
bool Bruch::operator==(const Bruch& ref) const
{
	if(this->zaehler == ref.get_zaehler() && this->nenner == ref.get_nenner())
		return true;
	else
		return false;
}
bool Bruch::operator!=(const Bruch& ref) const
{
	if(this->zaehler == ref.get_zaehler() && this->nenner == ref.get_nenner())
		return false;
	else
		return true;
}
Bruch Bruch::operator*=(const Bruch&ref)
{
	this->zaehler *= ref.get_zaehler();
	this->nenner *= ref.get_nenner();
	this->normalize();
	return *this;
}
Bruch operator*(Bruch b1, Bruch b2)
{
	int _zaehler = b1.get_zaehler() * b2.get_zaehler();
	int _nenner = b1.get_nenner() * b2.get_nenner();
	Bruch temp(_zaehler, _nenner);
	return temp;
}
Bruch operator*(int zahl, Bruch b)
{
	int _zaehler = zahl * b.get_zaehler();
	Bruch temp(_zaehler, b.get_nenner());
	return temp;
}
std::ostream& operator<<(std::ostream& stream, Bruch ref)
{
	stream << ref.get_zaehler() << "/" << ref.get_nenner();
	return stream;
}
