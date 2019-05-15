#include "sequence.h"


using namespace std;

int main()
{

	Sequence<int> test(1);
	int old_cap = 1;
	show(test);
	while(test.capacity() < 100)
	{
		test.push_back(17);
		if(old_cap != test.capacity())
		{
			cout << "Kapazitätsänderung von " << old_cap << " auf " << test.capacity() << endl;
			old_cap = test.capacity();
		}
	}
	show(test);
}
