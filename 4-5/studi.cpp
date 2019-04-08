#include "studi.h"

bool operator>>(std::ifstream& file, studi& obj)
{
	std::string word;
	int valuecnt = 0; //counter for expression

	while(file >> word)
	{
		if(valuecnt == 0)
		{
			obj.s_matnr(stol(word));
			valuecnt++;
			continue;
		}
		if(valuecnt == 1)
		{
			obj.s_vorname(word);
			valuecnt++;
			continue;
		}
		if(valuecnt == 2)
		{
			obj.s_nachname(word);
			return true;
		}
		else
			throw std::runtime_error("error reading data from file");
	}
	return false;
}

std::ostream& operator<<(std::ostream& stream, const studi obj)
{
	stream << obj.g_matnr() << " " << obj.g_vorname() << " " << obj.g_nachname();
	return stream;
}
