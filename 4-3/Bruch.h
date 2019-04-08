#ifndef _BRUCH
#define _BRUCH
#include <iostream>

class Bruch{
private:
	int inner_zaehler;
	int inner_nenner;
	void normalize();
	int ggt(int, int) const;
public:
	//standard-methods
	Bruch(): inner_zaehler(0), inner_nenner(0) { }
	Bruch(int _zaehler): inner_zaehler(_zaehler), inner_nenner(1) {}
	Bruch(int _zaehler, int _nenner): inner_zaehler(_zaehler), inner_nenner(_nenner) { this->normalize(); }
	~Bruch() {}
	Bruch(const Bruch& ref)
	{
		this->inner_zaehler = ref.get_zaehler();
		this->inner_nenner = ref.get_nenner();
	}
	//getter-methods
	int get_zaehler() const { return this->inner_zaehler; }
	int get_nenner() const { return this->inner_nenner; }
	//setter-methods
	void set_zaehler(int value)
	{
		this->inner_zaehler = value;
		this->normalize();
	}
	void set_nenner(int value)
	{
		this->inner_nenner = value;
		this->normalize();
	}
	//operator-methods
	bool operator==(const Bruch) const;
	bool operator!=(const Bruch) const;
	Bruch operator*=(const Bruch&);

};

Bruch operator*(Bruch, Bruch);
Bruch operator*(int, Bruch);
std::ostream& operator<<(std::ostream&, Bruch);
bool operator==(const int, const Bruch);
bool operator!=(const int, const Bruch);

#endif
