#include "header.h"
using namespace std;

int main()
{
	vector<int> a = create_randints(10,0,100);

	cout << "Array vor CountingSort:" << endl;
				for(size_t i = 0; i < a.size(); i++)
				{
					cout << "Element " << i << ": " << a[i] << endl;
				}

	counting_sort(a);

	cout << "Array nach CountingSort:" << endl;
			for(size_t i = 0; i < a.size(); i++)
			{
				cout << "Element " << i << ": " << a[i] << endl;
			}

	//check_sort(counting_sort, true);
}
