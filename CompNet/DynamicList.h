#ifndef __DYNAMICLIST_H
#define __DYNAMICLIST_H

#include "ItemType.h"

class DynamicList
{
private:
	ItemType* m_head; //Want to change to node
	ItemType* m_tail;
public:
	// C'tors
	DynamicList();
	DynamicList(const DynamicList&) = delete;
	DynamicList(DynamicList&&) = delete;
	~DynamicList();
	
	//Getters
	ItemType* getHead() const;
	ItemType* getTail() const;

	//Setters
	void setHead(ItemType* head);
	void setTail(ItemType* tail);

};


#endif // __DYNAMICLIST_H

