#include <iostream>
class Resistor{
protected:
	double resistance;
public:
	double ohm() const { return resistance; }
	Resistor(): resistance(0) {};
	Resistor(double value): resistance(value) {
		this->resistance = value;
	};
};

class Serial : public Resistor{
public:
	Serial(const Resistor& r1, const Resistor& r2)
	{
		resistance = r1.ohm() + r2.ohm();
	}
	void recalc(const Resistor& r1, const Resistor& r2)
		{
			resistance = r1.ohm() + r2.ohm();
		}
};

class Parallel : public Resistor{
public:
	Parallel(const Resistor& r1, const Resistor& r2)
	{
		resistance = (r1.ohm() * r2.ohm()) / (r1.ohm() + r2.ohm());
	}
	void recalc(const Resistor& r1, const Resistor& r2)
	{
		resistance = (r1.ohm() * r2.ohm()) / (r1.ohm() + r2.ohm());
	}
};

class Poti : public Resistor{
public:
	Poti() {
		resistance = 0;
	}
	Poti(double value) {
			resistance = value;
		}
	void set_ohm(double ohm)
	{
		resistance = ohm;
	}
};

using namespace std;
int main()
{
	Resistor r2(200), r3(300);// 3 Widerstaende
	Poti p1(100);
	Parallel par(p1, r2);// R1 und R2 parallel
	Serial ser(par, r3);// R1 || R2 seriell mit R3
	double val = 0;
	while(1)
	{
		cout << "Potentiometer einstellen: ";
		cin >> val;
		p1.set_ohm(val);
		par.recalc(p1,r2);
		ser.recalc(par,r3);
		cout << "Netzwiderstand: " << ser.ohm()// Netzwiderstand berechnen
			<< " Ohm" << endl << endl;
	}
}
