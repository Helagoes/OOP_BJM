#include "header.h"
using namespace std;

int main()
{
	/*for(size_t i = 1; i <= 16; i++)
	{*/
		vector<int> a = create_randints(10, 0, 1000);
		selection_sort(a);
		int first_error;
		if (!is_sorted(a, first_error))
		{
			cout << "NOT SORTED: " << first_error << endl;
		}
	//}
}
