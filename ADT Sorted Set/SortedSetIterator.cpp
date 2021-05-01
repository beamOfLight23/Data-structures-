#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	this->current = 0; 
}
// Complexity: theta(1)


void SortedSetIterator::first() {
	// go back to the beginning, reset our iterator
	this->current = 0; 
}
// Complexity: theta(1)


void SortedSetIterator::next() {
	// condition: iterator is valid 
	if (this->current >= this->multime.nrElements)
		throw exception();
	else
		this->current++; 

}
// Complexity: theta(1)


TElem SortedSetIterator::getCurrent()
{
	// condition: iterator is valid! 
	if (this->current >= this->multime.nrElements) {
		throw exception();
	}
	//	return current; 
	return this->multime.elements[this->current];
}
// Complexity: theta(1)

bool SortedSetIterator::valid() const {
	// invalid iterator: we reach the end of the arr 
	if (this->current < this->multime.nrElements)
		return true;
	else return false;
} // theta(1) 

