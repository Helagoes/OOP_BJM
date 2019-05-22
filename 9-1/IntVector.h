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
	class iterator{
	private:
		int* ptr;
	public:
		int* get_iterator() const { return this->ptr; }
		bool operator==(const int* ref)
		{
			if(ptr == ref)
				return true;
			else
				return false;
		}
		int* operator=(int* ref)
		{
			if(ptr != ref)
				ptr = ref;

			return ptr;

		}
		int* operator+=(size_t n)
		{
			ptr = ptr + n;
			return ptr;
		}
		int& operator*()
		{
			return *(this->ptr);
		}
	};

	iterator vect_iterator;

	bool iterator_frwd(int pos=1) //returns true if iterator was reset during forward, else false
	{
		this->vect_iterator += pos;
		if( vect_iterator == (start_adr + len) )
		{
			vect_iterator = start_adr;
			return true;
		}
		return false;
	}
	IntVector(size_t _len): len(_len)
	{
		this->start_adr = new int[len];
		vect_iterator = start_adr;
	}
	~IntVector()
	{
		delete [] this->start_adr;
	}
	IntVector(const IntVector &ref): len(ref.size())
	{
		this->start_adr = new int[ref.size()];
		vect_iterator = start_adr;
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
