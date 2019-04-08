#include "Vektor.h"

using namespace std;

int main(int argc, char* argv[])
{
	Vektor test;
	Vektor ziel;
	test.set_ele(1) = 2;
	ziel = test;
	Vektor kopie(ziel);
	ziel.resize(4);

	cout << "test" << endl << "size: " << test.size() << endl;
	for (size_t i=0; i < test.size(); i++)
		cout << "Element " << i << ": " << test.get_ele(i) << endl;


	cout << "ziel" << endl << "size: " << ziel.size() << endl;
	for (size_t i=0; i < ziel.size(); i++)
		cout << "Element " << i << ": " << ziel.get_ele(i) << endl;

	cout << "kopie" << endl << "size: " << kopie.size() << endl;
	for (size_t i=0; i < kopie.size(); i++)
		cout << "Element " << i << ": " << kopie.get_ele(i) << endl;

}
