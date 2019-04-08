#include <iostream>
#include "bruch.h"

using namespace std;

int main(int argc, char* argv[])
{
	Bruch b1(8,16);
	Bruch b2(2,4);

	if(b1 == b2)
		cout << "Die Brüche sind gleich!" << endl;
	else
		cout << "Fehler. Noch einmal drüberschauen..." << endl;

	Bruch b3 = 2*b2;

	cout << "2 mal " << b2 << "ergibt: " << b3;
}
