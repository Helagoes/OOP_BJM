#include "linear_list.h"

linear_list::linear_list(): len(1), start(nullptr), iterator(nullptr) //erzeuge liste mit einem element
{
	this->start = new node;
}

linear_list::linear_list(size_t length, int intval): len(length), start(nullptr), iterator(nullptr) //erzeuge liste mit einem element
		{ //Hier nochmal drüberschauen
			this->start = new node;
			node* curr = this->start;
			this->iterator = this->start;
			curr->prev = nullptr;
			for(size_t i = 0; i < length-1; i++) //hänge length-1 elemente noch an, da eine liste nach erzeugung immer mindestens 1 element enthält
			{
				curr->next = new node;
				curr->next->prev = curr;
				curr->val = intval;
				curr->index = i;
				curr = curr->next;
			}
			//schreibe werte in letzten knoten
			curr->next = nullptr;
			curr->val = intval;
			curr->index = length-1;
		}

linear_list::~linear_list()
	{
		node* to_del = nullptr; //zu löschender knoten
		size_t stat_len = len;
		for(size_t i = 1; i <= stat_len; i++) //gehe gesamte listenlänge durch (nicht len, da len sich im durchlauf verändert)
		{
			to_del = this->jump_to(len-i); //springe zum jeweils letzten element
			delete to_del;
		}
	}

bool linear_list::delete_node(size_t idx) //lösche knoten an position idx (idx = 0 resultiert im nullptr, daher auch zulässig, aber ohne effekt)
	{
		node* ptr_node = this->jump_to(idx);
		node* to_del = ptr_node;

		if(ptr_node->prev == nullptr) //erster knoten, alle indizes um 1 verringern
		{
			ptr_node->next->prev = nullptr;

			while(ptr_node != nullptr)
			{
				ptr_node->index -= 1;
				ptr_node = ptr_node->next;
			}

		}
		if(ptr_node->next == nullptr) //letzter knoten, indizes bleiben unverändert
		{
			ptr_node->prev->next = nullptr;
		}
		else //knoten mittendrin, alle nachfolgenden indizes um 1 verringert
		{
			ptr_node->prev->next = ptr_node->next;
			ptr_node->next->prev = ptr_node->prev;
			while(ptr_node != nullptr)
			{
				ptr_node->index -= 1;
				ptr_node = ptr_node->next;
			}

		}
		len--;
		delete to_del;
		return true;
	}
node* linear_list::jump_to(size_t idx) //geht knoten der liste bis zum element idx durch
	{
		node* ptr_node = start; //fange am anfang der liste an

		if(idx >= this->len)
		{
			throw std::runtime_error("index out of list-range");
			return nullptr;
		}

		for(size_t i = 0; i < idx; i++)
		{
			ptr_node = ptr_node->next;
		}
		return ptr_node;
	}
node linear_list::insert_behind(size_t idx, int v) //hänge knoten hinter gegebenen knoten an
	{
		node* ptr_node = this->jump_to(idx);
		this->len++;
		node* temp;
		node* here = new node; //neuer zu erzeugender knoten/eintrag

		if(ptr_node->next == nullptr) //neues vorheriges element war ehemals letztes
			temp = nullptr;
		if(ptr_node->next != nullptr) //neues vorheriges element lag irgendwo zwischendrin
			temp = ptr_node->next;

		here->next = temp;
		here->prev = ptr_node;
		here->prev->next = here;
		here->val = v;
		here->index = here->prev->index; //muss nicht um 1 erhöht werden, das macht die schleife danach mit
		while((ptr_node = ptr_node->next) != nullptr)
		{
			ptr_node->index +=1;
		}

		return *here;
	}
node linear_list::insert_before(size_t idx, int v) //hänge knoten hinter gegebenen knoten an
	{
		node* ptr_node = this->jump_to(idx);

		len++;
		node* temp;
		node* here = new node; //neuer zu erzeugender knoten/eintrag

		if(ptr_node->prev == nullptr) //neues hinteres element war ehemals erstes
			temp = nullptr;
		if(ptr_node->prev != nullptr) //neues hinteres element lag irgendwo zwischendrin
			temp = ptr_node->prev;

		here->prev = temp;
		here->next = ptr_node;
		here->next->prev = here;
		here->val = v;

		return *here;
	}

int& linear_list::operator[](size_t idx)
	{
		node* to_return = this->jump_to(idx);
		return to_return->val;
	}

node* linear_list::get_iterator() //springt automatisch einen knoten weiter
	{
		node* ret_val = this->iterator;
		if( !( !(this->iterator != nullptr) || !(this->iterator->next == nullptr)) )
			/*Ausdruck if(!(!A || !B)) ist äquivalent zu A && B,
			 * Ausdruck so gewählt, damit kein Fehler durch
			 * Zugriffsversuch auf Nullpointer */
		{
			this->iterator = nullptr;
		}
		else if(this->iterator != nullptr)
			this->iterator = this->iterator->next;
		return ret_val;
	}

std::ostream& operator<<(std::ostream& stream, linear_list& list)
{
	list.iterator_reset();
	node* current = list.get_iterator();
	while(current != nullptr)
	{
		stream << "List[" << current->index << "]: " << current->val << std::endl;
		current = list.get_iterator();
	}
	list.iterator_reset();
	return stream;
}
