#ifndef LIST
#define LIST

#include <cstdlib>
#include <stdexcept>
#include <iostream>

struct node{
	int val;
	node* prev;
	node* next;
	size_t index;
};
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
class linear_list {
private:
	std::size_t len;
	node* start; //kein echter knoten, nur zeiger auf knoten!!
	node* iterator; //interner zeiger

public:
	//standardmethoden, für nutzung irrelevant
	linear_list();
	linear_list(size_t length, int intval=0);
	~linear_list();

	/*	@param idx: idx-ter knoten, hinter dem ein neuer knoten eingefügt werden soll
	 *	@param v: zu schreibender int-wert, inital 0
	 *	@return: gibt den neu angelegten knoten selbst zurück
	 */
	node insert_behind(size_t idx, int v=0); //hänge knoten hinter gegebenen knoten an

	/*	@param idx: idx-ter knoten, vor dem ein neuer knoten eingefügt werden soll
	 *	@param v: zu schreibender int-wert, inital 0
	 *	@return: gibt den neu angelegten knoten selbst zurück
	 */
	node insert_before(size_t idx, int v=0); //hänge knoten hinter gegebenen knoten an

	/*	@param idx: idx-ter knoten, der gelöscht werden soll
	 *  die liste ist nach gebrauch weiter intakt, das element wird sauber "herausgeschnitten"
	 *  @return: true nach löschung
	 */
	bool delete_node(size_t idx); //lösche knoten an position idx (idx = 0 resultiert im nullptr, daher auch zulässig, aber ohne effekt)

	/*	@param idx: idx-ter knoten, zu dem hingesprungen werden soll
	 * achtung, eignet sich nicht zum gebrauch bei ausgabe oder sequentiellem schreiben der liste, da die liste immer wieder von
	 * anfang an durchlaufen wird
	 * @return: der zielknoten, zu dem gesprungen
	 */
	node* jump_to(size_t idx);

	/*@param val: wert, der in den voranzustellenden knoten geschrieben werden soll
	 * pop analog zu selbiger funktion beim CommonVector
	 */
	void push_back(int val=0) { this->insert_behind(len-1, val); }

	/*@param val: wert, der in den anzuhängenden knoten geschrieben werden soll
	 * push_back analog zu selbiger funktion beim CommonVector
	 */
	void pop(int val=0) { this->insert_before(0, val); }

	/*
	 * selbsterklärend, gibt die länge der liste zurück, erkennt jedoch keine "mogeleien" (wie das aushängen eines knotens durch
	 * verändern der next- und prev-zeiger, ohne, dass der knoten gelöscht wird)
	 */
	size_t size() const { return this->len; }
	int& operator[](size_t idx);

	/*
	 * gibt die adresse des ersten knotens in der liste zurück
	 */
	node* get_start() { return this->start; }

	/*
	 * gibt den aktuellen wert des iterators aus und springt selbstständig zum nächsten knoten
	 * @return: zeiger auf den aktuellen knoten
	 */
	node* get_iterator();

	/*
	 * setzt den iterator der liste zurück an den listenanfang
	 */
	void iterator_reset() { this->iterator = this->start;
	std::cout << "Iterator zurückgesetzt" << std::endl;}
};

std::ostream& operator<<(std::ostream& stream, linear_list& list);

#endif
