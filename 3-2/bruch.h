#ifndef _BRUCH
#define _BRUCH
#include <iostream>

class Bruch{
private:
	int zaehler;
	int nenner;
	void normalize();
	int ggt(int, int) const;
public:
	//standard-methods
	Bruch(): zaehler(0), nenner(0) { }
	Bruch(int _zaehler): zaehler(_zaehler), nenner(1) {}
	Bruch(int _zaehler, int _nenner): zaehler(_zaehler), nenner(_nenner) { this->normalize(); }
	~Bruch() {}
	Bruch(const Bruch& ref)
	{
		this->zaehler = ref.get_zaehler();
		this->nenner = ref.get_nenner();
	}
	//getter-methods
	int get_zaehler() const { return this->zaehler; }
	int get_nenner() const { return this->nenner; }
	//setter-methods
	void set_zaehler(int value)
	{
		this->zaehler = value;
		this->normalize();
	}
	void set_nenner(int value)
	{
		this->nenner = value;
		this->normalize();
	}
	//operator-methods
	bool operator==(const Bruch&) const;
	bool operator!=(const Bruch&) const;
	Bruch operator*=(const Bruch&);

};

Bruch operator*(Bruch, Bruch);
Bruch operator*(int, Bruch);
std::ostream& operator<<(std::ostream&, Bruch);

#endif
