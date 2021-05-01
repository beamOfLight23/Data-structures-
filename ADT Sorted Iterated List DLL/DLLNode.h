#pragma once
typedef int TComp;


class DLLNode
{
public: 
	TComp info; 
	DLLNode* next; 
	DLLNode* prev; 
/*public: 
	DLLNode(); 
	DLLNode(TComp element, DLLNode* previous, DLLNode* next );
	TComp getElement() const; 
	void setElement(TComp element); 
	DLLNode* getPrevElement() const; 
	DLLNode* getNextElement() const; 
	void setPrevElement(DLLNode* prevElem); 
	void setNextElement(DLLNode* nextElem); */ 

};

