#include "linear_list.h"

using namespace std;

int main()
{
	//Liste anlegen
	linear_list list(6, 0);


	//Zufallsgenerator seeden
	srand(time(NULL));

	//Liste mit Zufallswerten füllen
	for(size_t i = 0; i < list.size(); i++)
	{
		list[i] = rand() % 253688;
	}

	//Probeausgabe
	cout << list << endl;

	//Lösche Knoten 4
	list.delete_node(4);

	//Probeausgabe
	cout << list << endl;

	//Hänge hinter 11 ein Element an
	list.push_back();

	//Probeausgabe
	cout << list << endl;
}
