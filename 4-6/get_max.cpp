#include "get_max.h"
using namespace std;

int main(int argc, const char* argv [])
{
	argsp_t command(argc,argv);
	std::string filename = command.pos(0);
	generate_rand_into_file(filename, 999, 999999);
	cout << get_max(filename);

}
void generate_rand_into_file(string filename, size_t how_many, size_t max)
{
	std::fstream file(filename);
	srand(time(NULL));
	for (size_t i = 0; i < how_many; i++)
	{
		file << rand() % max << endl;
	}
	file.close();
}
long get_max(string filename)
{
	std::fstream file(filename);
	long max = -1;
	std::string temp;
	while(file >> temp)
	{
		if(max < stol(temp))
			max = stol(temp);
	}
	return max;
}
