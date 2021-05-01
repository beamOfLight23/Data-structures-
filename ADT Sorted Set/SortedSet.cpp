#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <exception>
#include <iostream>
using namespace std; 

SortedSet::SortedSet(Relation r) {
	this->nrElements = 0; 
	this->capacity = 100; 
	this->relation = r; 
	this->elements = new TElem[this->capacity]; 
}
// Complexity: Theta(1)

void SortedSet::resize() {
	TElem* auxArray = new TElem[this->capacity * 2];
	for (int index = 0; index < this->nrElements; index++)
		auxArray[index] = this->elements[index];
	delete[] this->elements;
	this->elements = auxArray;
	this->capacity = this->capacity * 2;
}
// Complexity: Theta(n) for a n-size array 


bool SortedSet::add(TComp elem) {
	for (unsigned index = 0; index < this->nrElements; index++)
		if (this->elements[index] == elem)
			return false; // we must have unique elements 

	if (this->capacity == this->nrElements)
		this->resize(); 

	if (this->nrElements == 0)
	{
		this->elements[this->nrElements] = elem; 
		this->nrElements++; 
		return true; 
	}
	else
	{
		for (int index = 0; index < this->nrElements; index++) 
			if (relation(elem, this->elements[index]) == true) {
				for (int index2 = this->nrElements; index2 > index; index2--)
					this->elements[index2] = this->elements[index2 - 1];
				this->elements[index] = elem;
				this->nrElements++;
				return true;

			}
		
	
		this->elements[this->nrElements] = elem;
		this->nrElements++;
		return true; 
	}
	
}



bool SortedSet::remove(TComp elem) {
	for (int index = 0; index < this->nrElements; index++)
		if (elem == this->elements[index]) {
			for (int index2 = index; index2 < this->nrElements; index2++)
				this->elements[index2] = this->elements[index2 + 1];
			this->nrElements--;
			return true; 
		}
	return false;
}


bool SortedSet::search(TComp elem) const {
	for (int index = 0; index < this->nrElements; index++)
		if (elem == this->elements[index])
			return true; 
	
	return false;
}



int SortedSet::size() const {
	return this->nrElements; 

}
// Complexity: Theta(1)


bool SortedSet::isEmpty() const {
	if (this->nrElements == 0)
		return true; 
	return false; 
}
// Complexity: Theta(1)

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}
// Complexity: Theta(1)


SortedSet::~SortedSet() {
	delete[] this -> elements; 
}

// Complexity: Theta(1) 


