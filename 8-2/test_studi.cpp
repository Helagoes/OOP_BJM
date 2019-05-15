#include "studi.h"
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[])
{
	std::ifstream file("studis.txt");
	std::string waste;
	size_t len = 0;
	//calc length of file
	while(getline(file, waste))
	{
		len++;
	}
	file.clear(); // clear bad state after eof
	file.seekg( 0 );

	vector<studi> allstudis(len);

	for(size_t i = 0; i < allstudis.size(); i++)
	{
		file >> allstudis[i];
		cout << allstudis[i] << endl;
	}
	file.close();
}
