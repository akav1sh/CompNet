#ifndef __STATICLIST_H
#define __STATICLIST_H

#include "ListNode.h"

class StaticList
{
private:
	ListNode*  m_array;
	int        m_headList;
	int        m_headFree;
	int        m_size;

public:
	// C'tors
	 StaticList(int size);
	 StaticList(const StaticList&) = delete;
	 StaticList(StaticList&&)      = delete;
	~StaticList();
	//Getters
	ListNode* getArray();
	int getHeadList();
	int getHeadFree();
	int getSize();

	
	// Methods
	void addItemToEndOfList(PC* pc);
};


#endif // __STATICLIST_H
