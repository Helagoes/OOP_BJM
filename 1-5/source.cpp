#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char* argv[])
{
	ifstream numbers("numbers.txt");

	string line;

	while(numbers >> line)
	{
		cout << line << endl;
	}
}
