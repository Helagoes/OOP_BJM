#include "ooptool.h"
#include "IntVector.h"
#include <vector>
#include <utility>

using namespace std;

int main(int argc, const char* argv[])
{
	argsp_t cmd(argc, argv);
	int lower = cmd.int_pos(0,0);
	int upper = cmd.int_pos(1,10000);
	int sum = 0;

	IntVector a(upper-lower+1);

	*(a.get_iterator()) = lower;
	sum += lower;

	for(size_t i = lower+1; !(a.iterator_frwd()); i++)
	{
		*(a.get_iterator()) = i;
		sum += i;
	}


	if(sum >= 0)
		cout << "sum=" << sum << endl;
	else
		throw runtime_error("overflow-error: sum grew too big and became negative");
}
