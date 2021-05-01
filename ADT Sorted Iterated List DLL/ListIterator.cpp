#include "ListIterator.h"
#include "SortedIteratedList.h"
#include <exception>


using namespace std;

ListIterator::ListIterator(const SortedIteratedList& list) : list(list){
	// we set the iterator to be the head 
	if (list.isEmpty())
		currentNode = nullptr;
	else
		currentNode = list.head; 
}
// Total complexity: Theta(1)

void ListIterator::first(){
	
	currentNode = list.head; 
}
// Total complexity: Theta(1)

void ListIterator::next(){
	if (!valid()) {
		throw exception("error"); 
	}
	
	currentNode = currentNode->next; 

}
// Total complexity: Theta(1)

bool ListIterator::valid() const{

	return currentNode != nullptr; 
	 
}
// Total complexity: Theta(1)

TComp ListIterator::getCurrent() const{
	if (!valid()) {
		throw exception("Not valid.");
	}
	return currentNode->info; 
}
// Total complexity: Theta(1)


