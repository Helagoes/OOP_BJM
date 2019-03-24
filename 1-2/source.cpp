#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include "ooptool.h"
using namespace std;

int main(int argc, char* argv[]) //binarisieren lena.pgm out.pgm 25
{

	vector<int> pic = read_pgm("lena.pgm");

	int max_brightness = pic[2];
	float n = 0.8;//atof(argv[3]);

	for(size_t i = 3; i < pic.size(); i++)
	{
		if(pic[i] < n*max_brightness)
			pic[i] = 0;
		else
			pic[i] = max_brightness;
	}
	save_pgm("out.pgm", pic);

}
