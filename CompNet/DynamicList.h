#ifndef __DYNAMICLIST_H
#define __DYNAMICLIST_H

#include "Node.h"

class DynamicList
{
private:
	Node* m_head; //Want to change to node
	Node* m_tail;
public:
	// C'tors
	 DynamicList ();
	 DynamicList (const DynamicList&) = delete;
	 DynamicList (DynamicList&&)      = delete;
	~DynamicList ();
	
	//Getters
	Node* getHead () const;
	Node* getTail () const;

	//Setters
	void setHead (Node* head);
	void setTail (Node* tail);

};


#endif // __DYNAMICLIST_H

