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
};

class Parallel : public Resistor{
public:
	Parallel(const Resistor& r1, const Resistor& r2)
	{
		resistance = (r1.ohm() * r2.ohm()) / (r1.ohm() + r2.ohm());
	}
};

using namespace std;
int main()
{
	Resistor r1(100), r2(200), r3(300);// 3 Widerstaende
	Parallel par(r1, r2);// R1 und R2 parallel
	Serial ser(par, r3);// R1 || R2 seriell mit R3
	cout << "Netzwiderstand Netz1: " << ser.ohm()// Netzwiderstand berechnen
			<< " Ohm" << endl;

	Resistor r4(100), r5(200), r6(300), r7(400);// 3 Widerstaende
		Serial ser2(r4, r5);// R4 und R5 in Reihe
		Serial ser3(ser2, r6); // R4 und R5 und R6 in Reihe
		Parallel par2(ser3, r7);// R7 parallel zu (R4 + R5 + R6)
		cout << "Netzwiderstand Netz2: " << par2.ohm()// Netzwiderstand berechnen
				<< " Ohm" << endl;
}
