#pragma once
#include "SortedIteratedList.h"
#include "DLLNode.h"



//DO NOT CHANGE THIS PART
class ListIterator{
	friend class SortedIteratedList;
private:
	const SortedIteratedList& list;
	DLLNode* currentNode;
	
	ListIterator(const SortedIteratedList& list);

	//TODO - Representation
public:
	void first();
	void next();
	bool valid() const;
    TComp getCurrent() const;
};


