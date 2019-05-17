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
	linked_queue<T>(): size(0)
	{
		start = nullptr;
		end = nullptr;
	}
	linked_queue<T>(size_t length, T ele): size(length)
	{
		start = new node<T>();
		node<T>* current = start;
		current->val = ele;

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
	void out()
	{
		node<T>* current = start;
		for(size_t i = 0; i < get_size(); i++)
		{
			std::cout << "Element " << i << ":" << current->val << std::endl;
			current = current->next;
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
			queue.out();

			while(queue.get_size() != 1)
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

		while(queue.get_size() != 1)
		{
			queue.leave();
		}
		std::cout << "Größe nach dem Löschen: " <<  queue.get_size() << std::endl;

}
