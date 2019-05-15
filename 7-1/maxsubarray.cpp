#include <iostream>
#include <vector>
using namespace std;

void maxsubarray(vector<int> a)
{
	int maxsum = a[0]; //intialisiere mit wert von a[0], sodass ein gültiger wert geschrieben ist
	int tempsum = 0;
	size_t start_index = 0; //Anfangsindex des größten Sub-Arrays
	size_t end_index = 0; //Endindex des größten Sub-Arrays

	for(size_t i = 0; i < a.size(); i++) //Startindexschleife
	{
		tempsum = 0;
		for(size_t j = i; j < a.size(); j++) //Endindexschleife
		{
				tempsum += a[j];

			if (tempsum > maxsum) //Neue gefundene Summe ist größer als vorher gefundene
			{
				maxsum = tempsum;
				start_index = i;
				end_index = j;
			}
		}
	}

	cout << "Größtes Sub Array mit Summe " << maxsum << ", von Index " << start_index << " bis " << end_index << endl;
}

int main()
{
	vector<int> test{31,-41,59,26,-53,58,97,-93,-23,84};
	maxsubarray(test);
	//Komplexität des einfachen Algorithmus: 	O(n!)
	//Komplexität des verbesserten Algorithmus: O(n²)

}
