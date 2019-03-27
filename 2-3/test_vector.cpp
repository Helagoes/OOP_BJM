#include "intvector.h"
#include <time.h>
#include <iostream>

void klappt(size_t, intvector);
void crash(intvector);

int main(int argc, char* argv[])
{
	size_t n = 17;
	intvector testvec(n);
	klappt(n, testvec);
	crash(testvec);
}
void klappt(size_t n, intvector testvec)
{
	srand(time(NULL));

	for(size_t i = 0; i < testvec.size(); i++)
	{
		testvec.at(i) = (rand()%17);
	}

	std::cout << "Länge des Vektors: " << testvec.size() << std::endl;
	testvec.out();

	for(size_t i = 0; i < testvec.size(); i++)
		{
			testvec.at(i) = testvec.at(i) + 42;
		}
	std::cout << "Länge des Vektors: " << testvec.size() << std::endl;
	testvec.out();
}

void crash(intvector testvec)
{
	testvec.at(42);
}
