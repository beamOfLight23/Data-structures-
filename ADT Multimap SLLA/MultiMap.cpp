#include "MultiMap.h"
#include "MultiMapIterator.h"
#include <exception>
#include <iostream>

using namespace std;


MultiMap::MultiMap() {
	this->capacity = 10;
	this->slla = new TElem[this->capacity + 1];
	this->next = new int[this->capacity + 1]; // the same capacity as store arr
	this->head = -1;
	this->firstEmpty = 1;
	this->length = 0;
	int index;
	for (index = 1; index <= this->capacity - 1; index++)
		this->next[index] = index + 1;
	this->next[this->capacity] = -1;
}

// Total complexity: Theta(capacity)


void MultiMap::resize() {
	this->firstEmpty = this->capacity + 1;
	this->capacity *= 2;
	TElem* newSLLA = new TElem[this->capacity + 1];
	int* newNext = new int[this->capacity + 1];

	int index;
	for (index = 1; index <= this->length; index++)
	{
		newSLLA[index] = this->slla[index];
		newNext[index] = this->next[index];
	}
		
	for (index = this->length + 1; index <= this->capacity - 1; index++)
		newNext[index] = index + 1;
	newNext[this->capacity] = -1;
	delete[] this->slla;
	delete[] this->next;
	this->slla = newSLLA;
	this->next = newNext;
}

// Total complexity: Theta(capacity*2)


void MultiMap::add(TKey c, TValue v) {
	TElem element;
	element.first = c; // key 
	element.second = v; // value 
	if (this->firstEmpty == -1)
		this->resize();

	int occupiedPosition = this->firstEmpty; 
	this->slla[occupiedPosition] = element; 
	this->firstEmpty = this->next[this->firstEmpty];
	this->next[occupiedPosition] = this->head; 
	this->head = occupiedPosition; 
	this->length++; 
}

// Total complexity: Theta(1)



bool MultiMap::remove(TKey c, TValue v) {

	int current = this->head;
	TElem element; // to be removed
	element.first = c;
	element.second = v;
	int previous = -1;
	while (current != -1 && this->slla[current] != element)
	{
		previous = current;
		current = this->next[current];
	}
	if (current != -1)
	{
		if (current == this->head)
		{
			this->head = this->next[this->head];
		}
		else
		{
			this->next[previous] = this->next[current];
		}
		this->next[current] = this->firstEmpty;
		this->firstEmpty = current;
		this->length--;
		return true;
	}
	else
		return false;
}
/*
BC: Theta(1) (when we have no elements to remove)
WC: Theta(length)  (because we must iterate over the entire array)
AC: Theta(length) (worst case)
Total complexity: O(length)
*/


vector<TValue> MultiMap::search(TKey c) const {
	
	vector<TValue> vectorOfValues;
	int current = this->head;
	while (current != -1)
	{
		if (this->slla[current].first == c)
			vectorOfValues.push_back(this->slla[current].second);
		current = this->next[current];
	}
	return vectorOfValues;
}
/*
BC: Theta(1)
WC: Theta(length)
AC: Theta(length)
Total complexity: O(length)
*/


int MultiMap::size() const {
	return this->length;
}

// Total complexity: Theta(1)



bool MultiMap::isEmpty() const {

	if (this->length == 0)
		return true;
	else
		return false;
}

// Total complexity: Theta(1)


MultiMapIterator MultiMap::iterator() const {
	return MultiMapIterator(*this);
}

// Total complexity: Theta(1)



MultiMap::~MultiMap() {
	
	delete[] this->slla;
	delete[] this->next;
}

// Total complexity: Theta(1)


