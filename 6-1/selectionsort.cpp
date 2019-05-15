#include "header.h"
using namespace std;

void selection_sort(vector<int>& vec, bool onlytimes)
{
	size_t len = vec.size();

	//Nur Dokumentation
	if(onlytimes == false)
	{
		cout << "Array vor SelectionSort" << endl;
		for(size_t i = 0; i < len; i++)
		{
			cout << "Element " << i << ": " << vec[i] << endl;
		}
	}


	int temp_index;

	double time1=0.0, tstart; //Zeitvariablen anlegen
	tstart = clock();	// start

	for(size_t i = 0; i < len; i++)
	{
		temp_index = i; //gehe nach und nach alle elemente durch
		for(size_t j = i; j < len; j++) //beginne mit vergleichsschleife ab nächstem element
		{
			if(vec[j] < vec[temp_index])
				temp_index = j;
		}
		std::swap(vec[i], vec[temp_index]); //tausche zielelement an entsprechende stelle
	}

	time1 += clock() - tstart;     // ende
	time1 = time1/CLOCKS_PER_SEC;  // in Sekunden umwandeln
	time1 *= 1000;	//in Millisekunden umwandeln

	//Nur Dokumentation
	if(onlytimes == false)
	{
		cout << "Array nach SelectionSort, benötigte Zeit: " << time1 << " ms" << endl;
		for(size_t i = 0; i < len; i++)
		{
			cout << "Element " << i << ": " << vec[i] << endl;
		}
	}
	else
		cout << "Problemgröße " << len << ", benötigte Zeit: " << time1 << " ms" << endl;
}
