#ifndef _INTVECTOR
#define INTVECTOR

#include <cstdlib>
#include <stdexcept>

class IntVector
{
private:
	int* start_adr;
	size_t len;
public:
	IntVector(size_t _len): len(_len)
	{
		this->start_adr = new int[len];
	}
	~IntVector()
	{
		delete [] this->start_adr;
	}
	IntVector(const IntVector &ref): len(ref.size())
	{
		this->start_adr = new int[ref.size()];
		for(size_t i = 0; i < this->size(); i++)
				{
					(this->start_adr)[i] = (ref.start_adr)[i];
				}
	}
	size_t size() const
	{
		return this->len;
	}
	int& at(size_t);
	void out() const;
	IntVector &operator=(const IntVector&);
	int& operator[](const size_t);
};

#endif
