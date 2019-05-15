#ifndef SEQUENCE_CPP
#define SEQUENCE_CPP

#include "sequence.h"

template<typename T>
class Sequence {
public:
	Sequence(size_t cap): _cap(cap)
	{
		this->_array = new T[_cap];
		this->_size = 0;
	}
	Sequence(const Sequence &ref): _cap(ref.capacity()), _size(ref.size())
	{
		_array = new T[ref.capacity()];

		for(size_t i = 0; i < ref.size(); i++)
		{
			this->_array[i] = ref[i];
		}
	}
	Sequence &operator=(const Sequence &ref)
	{
		Sequence temp(ref);
		std::swap(_array, temp._array);
		std::swap(_cap, temp._cap);
		std::swap(_size, temp._size);
		return *this;
	}
	~Sequence()
	{
		delete [] this->_array;
	}
	size_t size() const { return this->_size; }
	size_t capacity() const { return this->_cap; }
	bool is_empty() const
	{
		if(this->_size == 0)
			return true;
		else
			return false;
	}
	bool is_full() const
	{
		if(this->_size == this->_cap)
		{
			return true;
		}
		else
			return false;
	}
	T &operator[](size_t pos)
	{
		return *(this->_array + pos);
	}
	const T &operator[](size_t pos) const
	{
		return *(this->_array + pos);
	}
	void insert(size_t pos, const T &ele)
	{
		if (is_full())
		{
			int n = 0;

			if(_cap == 1 || _cap == 3) //Zahl ist ungerade
			{
				n = (_cap / 2) +1;
			}
			else
				n = _cap / 2;

			this->resize(n);
		}
		if (pos > _size)
		{
			throw std::runtime_error("Sequence::insert: pos out of bounds");
		}

		for(size_t idx =_size; idx > pos; idx--)
		{
			_array[idx] = _array[idx-1];
		}
		_size++;
		this->_array[pos] = ele;
	}
	void push_back(const T &ele)
	{
		insert(_size, ele);
	}
	void remove(size_t pos)
	{
		if(pos >= _size)
			throw std::runtime_error("Sequence::remove: pos out of bounds");

		_size--;
		for(size_t idx=pos; idx < _size; idx++)
		{
			_array[idx] = _array[idx+1];
		}
	}
	bool remove_ele(const T &ele)
	{
		size_t pos = 0;
		while (pos < _size && !(_array[pos] == ele))
		{
			pos++;
		}
		if (pos < _size)
		{
			remove(pos);
			return true;
		}
		return false;
	}
	//Ab hier Implementierung von Übungsaufgaben
	void resize(size_t n) //Eigentlich Verlängerung
	{

		Sequence temp(_cap+n);

		temp._size = this->_size;
		this->_cap = temp._cap;

		for(size_t i = 0; i < this->size(); i++)
		{
			temp[i] = this->_array[i];
		}

		std::swap(temp._array, _array);

	}

	private:
	T *_array;
	size_t _cap;
	size_t _size;
	};

template <typename T> void show(const Sequence<T> &seq)
{
	std::cout << "[" << seq.size() << "/" << seq.capacity() << "] ";
	for(size_t pos = 0; pos < seq.size(); pos++)
	{
		std::cout << seq[pos] << " ";
	}
	std::cout << std::endl;
}
#endif
