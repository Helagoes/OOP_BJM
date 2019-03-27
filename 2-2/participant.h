#ifndef _PARTICIPANT
#define _PARTICIPANT

#include "ntime.h"

static int count = 0;

class participant
{
private:
	std::string name;
	ntime runtime;
public:
	std::string get_name() const { return name; }
	ntime get_runtime() const { return runtime; }
	participant(): name("EMPTY"), runtime(0,0,0)
	{
		count++;
	}
	participant(const std::string _name, const ntime _runtime)
	{
		count++;
	}
	~participant()
	{
		count--;
	}
	participant(participant const&);
	int set_runtime(int time)
	{
		ntime temp_time(0,0,time);
		this->runtime = temp_time;
		return 0;
	}
	int set_name(std::string namestring)
		{
			this->name = namestring;
			return 0;
		}
};

#endif
