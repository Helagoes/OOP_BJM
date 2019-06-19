#include <iostream>
#include <unordered_map>
#include <time.h>
#include "hash_func.h"

using namespace std;

int main()
{
	//Mit Workaround, damit Mist mit "Eigene Klasse, aber Instanzierung durch unordered_map" nicht gebraucht wird
	//int const modvar entsprechend auf -1, 0, 10, 100, 1000 setzen, um verschiedene Zeiten zu ermitteln
	int const modvar = -1;
	double time1=0.0, tstart;      // time measurment variables
	tstart = clock();

	unordered_map<int, int> intmap;

	for(size_t i = 0; i < 30000; i++)
	{
		intmap.insert({hash_func(i, modvar), i});
	}
	for(size_t i = 0; i < 30000; i++)
		{
			intmap.find(hash_func(i, modvar));
		}

	time1 += clock() - tstart; //end time measurement
	time1 = time1/CLOCKS_PER_SEC;  // rescale to seconds

	cout << "  time = " << time1 << " sec." << endl;
}
