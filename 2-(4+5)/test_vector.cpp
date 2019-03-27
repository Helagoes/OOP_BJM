#include <time.h>
#include <iostream>
#include "IntVector.h"

void klappt(size_t, IntVector);
void crash(IntVector);

/*int main(int argc, char* argv[])
{
	size_t n = 17;
	IntVector testvec(n);
	klappt(n, testvec);
	crash(testvec);
}*/
void copyassign()
{
	IntVector Test(1);
	IntVector Ref(1);
	Test = Ref;
	IntVector Copy(Test);
}

void klappt(size_t n, IntVector testvec)
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

void crash(IntVector testvec)
{
	testvec.at(42);
}
