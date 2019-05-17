//Was müssten Sie ändern, wenn Sie die Reihenfolge des Iterator umdrehen wollen?
//Man müsste start und end vertauschen, um da es sich bei der implementierten Klasse um eine einfach verkettete Liste handelt. Somit ist
//nur ein Durchlaufen von start nach end möglich, da die Knoten jeweils nur einen "next"-Pointer besitzen.

#include <cstdlib>
#include <stdexcept>
#include <iostream>

template <typename T>
struct node{
	node* next;
	T val;
};
template <typename T>
class linked_queue{
private:
	node<T>* start;
	node<T>* end;
	node<T>* iterator;
	size_t size;

	linked_queue<T>(const linked_queue &ref)
	{
		//do nothing, copying is forbidden
	}
	linked_queue<T> operator=(const linked_queue &ref)
	{
		//do nothing, since assigning is forbidden
	}
public:
	//Standard-methods
	linked_queue<T>(): size(0), start(nullptr), end(nullptr), iterator(nullptr)
	{
	}
	linked_queue<T>(size_t length, T ele): size(length)
	{
		start = new node<T>();
		node<T>* current = start;
		current->val = ele;
		iterator = start;

		if(size == 1)
			end = start;

		for(size_t i = 1; i < size; i++)
		{
			if(i+1 < size)
			{ //analog: push_back(ele);
				current->next = new node<T>();
				current = current->next;
				current->val = ele;
			}
			else
			{
				current->next = new node<T>();
				current = current->next;
				current->val = ele;
				end = current;

			}
		}
	}
	~linked_queue()
	{
		while(get_size() != 0)
		{
			leave();
		}
	}
	size_t get_size() const { return this->size; }
	void leave()
	{
		if(!(is_empty()))
		{
			node<T>* temp = (*start).next;
			delete start;
			if(start == end)
				end = temp;

			start = temp;
			size--;
		}
		else
			throw std::runtime_error("linked_queue::leave(): queue is currently empty");
	}
	void enter(T ele)
	{
		size++;

		if(end == nullptr)
		{
			end = new node<T>;
			end->val = ele;
			start = end;
			iterator = start;
		}
		else
		{
			(*end).next = new node<T>;
			(*end).next->val = ele;
			end = end->next;
		}
			end->next = nullptr;
	}
	bool is_empty()
	{
		if(start == nullptr)
			return true;
		else
			return false;
	}
	node<T>* get_iterator()
	{
		return this->iterator;
	}
	void iterator_frwd()
	{
			if(iterator != nullptr)
				iterator = iterator->next;
			else
				throw std::runtime_error("linked_queue::iterator_frwd(): iterator already nullptr");
	}
	void iterator_reset()
	{
		this->iterator = this->start;
	}
	void out()
		{
			iterator = start;
			int i = 0;

			while(get_iterator() != nullptr)
			{
				std::cout << "Element " << i << ":" << iterator->val << std::endl;
				iterator_frwd();
				i++;
			}
		}

};

int main()
{
	linked_queue<int> queue;

	int value;

	//1, 2, 3 hinzufügen und löschen
	for(size_t k = 0; k < 3; k++)
	{
		for(size_t i = 0; i < k+1; i++)
		{
			value = i;
			queue.enter(value);
		}
		std::cout << "Größe vor dem Löschen: " <<  queue.get_size() << std::endl;

		while(queue.get_size() != 0)
		{
			queue.leave();
		}
		std::cout << "Größe nach dem Löschen: " <<  queue.get_size() << std::endl;
	}

	//1000 hinzufügen und löschen
	for(size_t i = 0; i < 1000; i++)
		{
			value = i;
			queue.enter(value);
			}
			std::cout << "Größe vor dem Löschen: " <<  queue.get_size() << std::endl;

		while(queue.get_size() != 0)
		{
			queue.leave();
		}
		std::cout << "Größe nach dem Löschen: " <<  queue.get_size() << std::endl;


	//#################################################################################################################################################
	//1, 2, 3 hinzufügen und 1 wenigerlöschen
	for(size_t k = 0; k < 3; k++)
	{
		for(size_t i = 0; i < k+1; i++)
			{
				value = i;
				queue.enter(value);
			}
			std::cout << "Größe vor dem Löschen: " <<  queue.get_size() << std::endl;
			std::cout << "Inhalt: " << std::endl;
			queue.out();
			std::cout << std::endl;

			while(queue.get_size() != 1)
			{
				queue.leave();
			}
			std::cout << "Größe nach dem Löschen: " <<  queue.get_size() << std::endl;
			std::cout << "Inhalt: " << std::endl;
						queue.out();
						std::cout << std::endl;
		}

	//1000 hinzufügen und löschen
	for(size_t i = 0; i < 1000; i++)
	{
		value = i;
		queue.enter(value);
	}
		std::cout << "Größe vor dem Löschen: " <<  queue.get_size() << std::endl;

		while(queue.get_size() != 1)
		{
			queue.leave();
		}
		std::cout << "Größe nach dem Löschen: " <<  queue.get_size() << std::endl;

}
