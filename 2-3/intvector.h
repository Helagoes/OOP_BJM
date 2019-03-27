#ifndef _INTVECTOR
#define INTVECTOR

#include <cstdlib>
#include <stdexcept>

class intvector
{
private:
	int* start_adr;
	size_t len;
public:
	intvector(size_t _len): len(_len)
	{
		this->start_adr = new int[len];
	}
	~intvector()
	{
		delete [] this->start_adr;
	}
	intvector(const intvector &ref)
	{
		this->start_adr = new int[ref.size()];
		this->len = ref.size();
	}
	size_t size() const
	{
		return this->len;
	}
	int& at(size_t);
	void out() const;
};

#endif
