#include "header.h"
using namespace std;

void counting_sort(vector<int>& vec)
{
	int max = vec[0];

	for(size_t i = 1; i < vec.size(); i++) //Ermittele Maximalelement
	{
		if(max < vec[i])
		{
			max = vec[i];
		}
	}

	vector<int> counter(max+1);

	for(size_t i = 0; i < vec.size(); i++) //Zähle Elementvorkommen für jeden Index i
	{
			counter[vec[i]]++;
	}

	size_t curr_ele = 0;
	for(size_t i = 0; i < vec.size(); i++)
	{
		while(counter[curr_ele] == 0)
		{
			curr_ele++; //Wenn keine Zahl an dem Index mehr vorhanden, gehe zum nächsten
		}
		vec[i] = curr_ele;
		counter[curr_ele]--; //Ziehe den aktuell geschriebenen Index einmal ab
	}
}
