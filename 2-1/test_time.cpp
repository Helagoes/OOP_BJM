#include <iostream>

#include "ntime.h"
using namespace std;


int main(int argc, char* argv[])
{
	ntime test;
	cout << "Die Zeit betraegt: " << test << endl
		 << "Zeit in Sekunden: " << test.justseconds() << endl;

	ntime toadd(2,2,8);
	test = test + toadd;

	cout << "Die Zeit betraegt nach Addition: " << test << endl
		 << "Zeit in Sekunden: " << test.justseconds() << endl;

}
