#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

int main(int argc, char* argv[])
{
	const double E = 0.000001;//pow(10, -6);
	int x = atof(argv[2]);
	double a_n = (0.5*(x+1));
	double a_n_old = 0.f;

	do
	{
		a_n_old = a_n;
		a_n = (a_n + (x/a_n))*0.5;

	}while (fabs(a_n - a_n_old) > E);

	cout << "Die Quadratwurzel von " << x << " lautet " << a_n << endl;
}
