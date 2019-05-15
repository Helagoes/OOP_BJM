#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int mergesum(vector<int> a, size_t li, size_t re)
{
	size_t mid = re/2;
	size_t left_sum = a[mid];
	size_t right_sum = a[mid+1];

	//Rand des linken Elements
	for(size_t i = 1; (mid - i) > li && (mid-i) >= 0; i++)
	{
		if(left_sum + a[mid - i] > left_sum)
			left_sum += a[mid - i];
	}
	//Rand des rechten Elements
	for(size_t i = 1; (mid + 1 + i) < re && (mid+i) < a.size(); i++)
	{
		if(right_sum + a[mid + 1 + i] > right_sum)
			right_sum += a[mid + 1 + i];
	}
	return (left_sum + right_sum);
}

int dnq_maxsubarray(vector<int> a, size_t li, size_t re)
{
	if(li == re)
	{
		return a[li];
	}
	else
	{
		size_t mid = re/2;
		return fmax(fmax(dnq_maxsubarray(a, li, mid), dnq_maxsubarray(a, mid+1, re)), mergesum(a, li, re));
	}
}
int main()
{
	//vector<int> test{31,-41,59,26,-53,58,97,-93,-23,84};
	vector<int> test{1, 2};
	int res = dnq_maxsubarray(test, 0, test.size()-1);
	cout << "Summe ist: " << res << endl;
	//Komplexität des einfachen Algorithmus: 	O(n!)
	//Komplexität des verbesserten Algorithmus: O(n²)

}
