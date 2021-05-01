#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIteratedList::SortedIteratedList(Relation r) {
	this->head = NULL;
	this->tail = NULL;
	this->r = r; 
	this->length = 0; 
	
}
// Total complexity: Theta(1)


int SortedIteratedList::size() const {
	
	/*DLLNode* current; 
	current = head; 
	int contor = 0; 
	while (current != nullptr) {
		++contor; 
		current = current->next;
	} 

	return contor; */ 

	return this->length; 
	
}
// Total complexity: Theta(1)

bool SortedIteratedList::isEmpty() const {
	//return length == 0;
	if (this->size() == 0)
		return true;
	else
		return false; 
	

//	return head == NULL; 
	
}
// Total complexity: Theta(1)

ListIterator SortedIteratedList::first() const {
	return ListIterator(*this); 
	
}
// Total complexity: Theta(1)

TComp SortedIteratedList::getElement(ListIterator poz) const {
	if (!poz.valid())
		throw exception("Error"); 
	return poz.getCurrent(); 
}
// Total complexity: Theta(1)

TComp SortedIteratedList::remove(ListIterator& poz) {
	if (!poz.valid())
		throw exception("error"); 
	TComp oldValue = poz.getCurrent(); 
	if (poz.currentNode == head) {
		DLLNode* secondElement = head->next; 
		head->next = nullptr; 
		head->prev = nullptr; 
		delete head; 
		head = secondElement; 
		if (head != nullptr)
			head->prev = nullptr; 
	}

	else if (poz.currentNode == tail) {
		DLLNode* beforeLastElement = tail->prev; 
		tail->next = nullptr; 
		tail->prev = nullptr; 
		delete tail; 
		tail = beforeLastElement; 
		if (tail != nullptr)
			tail->next = nullptr; 
	}

	else {
		DLLNode* next = poz.currentNode->next; 
		poz.currentNode->info = next->info; 
		poz.currentNode->next = next->next; 
		delete next; 
		next = nullptr; 
	}

	--length; 
	return oldValue; 
	
	
}

ListIterator SortedIteratedList::search(TComp e) const{
	auto iterator = first(); 
	while (iterator.valid()) {
		if (iterator.getCurrent() == e)
			return iterator; 
		iterator.next(); 
	}

	return iterator; 
}
// BC: Theta(1)
// WC: Theta(n)
// AC: Theta(n)
// Total complexity: O(n) 


void SortedIteratedList::add(TComp e) { // insert by relation
/*	// allocate 
	DLLNode* newNode = new DLLNode;
	
	newNode->info = e; 
	newNode->next = nullptr; 
	newNode->prev = nullptr; 

	if (head == nullptr)
		// the list is empty 
		head = newNode;
	else if (r(e, head->info == true)) {
		// elem is less than the info from the head 
		newNode->next = head;
		newNode->next->prev = newNode; 
		head = newNode;
	}
	else {
		// if it's "after" head, let's see where it is
		DLLNode* cn = head; // current node
		while (cn->next != nullptr && r(e, cn->next->info))
			cn = cn->next; 
		if (cn->next != NULL)
			newNode->next->prev = newNode; 
		cn->next = newNode; 
		newNode->prev = cn; 

	}

	DLLNode* cn = head; 
	while (cn->next != nullptr)
		cn = cn->next; 
	tail = cn; 
	tail->next = nullptr; 
	tail->prev = cn->prev; 
		*/ 

	DLLNode* newNode = new DLLNode;

	newNode->info = e;
	newNode->next = nullptr;
	newNode->prev = nullptr;

	if (head == nullptr)
		head = newNode; 
	else if (r(e, head->info) == true) {
		// punem elem inaintea lui head (fie ca e cresc sau descr) 
		newNode->next = head; 
		newNode->next->prev = newNode;
		head = newNode; 
	}

	else {
		DLLNode* cn = head; 
		while (cn->next != nullptr and !r(e, cn->next->info))
			cn = cn->next; 
		// now insert after cn 
		cn->next = newNode;
		newNode->prev = cn;

	}

	
	
	DLLNode* cn = head;
	while (cn->next != nullptr)
		cn = cn->next;
	tail = cn;
	tail->next = nullptr;
	tail->prev = cn->prev;
	
	
	++length; 
}
// Total complexity: O(n)

SortedIteratedList::~SortedIteratedList() {
	DLLNode* currentNode; 
	while (head != nullptr) {
		currentNode = head; 
		head = head->next; 
		delete currentNode; 
	}
	 
	
}
// Total complexity: O(n) - because we iterate over the list 
