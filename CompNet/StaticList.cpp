#include "StaticList.h"

//-------------------------------------------------------------------------------------------//
// C'tor
StaticList::StaticList(int size) : m_size(size)
{
	this->m_array = new ListNode[size]; //Allocate array with size recieved

	//Set empty list's next places
	int i;
	for (i = 0; i < size - 1; ++i)
	{
		this->m_array[i].m_next = i + 1;
	}
	this->m_array[i].m_next = ENDLIST;

	this->m_headFree =  0;
	this->m_headList = ENDLIST; //List doesn't exist yet so head is set to end
}
//-------------------------------------------------------------------------------------------//
StaticList::~StaticList() //D'tor
{
	delete[] this->m_array;
}
//-------------------------------------------------------------------------------------------//
StaticList::ListNode* StaticList::getArray()
{
	return this->m_array;
}
//-------------------------------------------------------------------------------------------//
int StaticList::getHeadList()
{
	return this->m_headList;
}
//-------------------------------------------------------------------------------------------//
int StaticList::getHeadFree()
{
	return this->m_headFree;
}
//-------------------------------------------------------------------------------------------//
int StaticList::getSize()
{
	return this->m_size;
}
//-------------------------------------------------------------------------------------------//
void StaticList::makeEmpty()
{
	delete this->m_array;

	this->m_array = new ListNode[this->m_size]; //Allocate array with size recieved

	//Set empty list's next places
	int i;
	for (i = 0; i < this->m_size - 1; ++i)
	{
		this->m_array[i].m_next = i + 1;
	}
	this->m_array[i].m_next = ENDLIST;

	this->m_headFree = 0;
	this->m_headList = ENDLIST; //List doesn't exist yet so head is set to end
}
//-------------------------------------------------------------------------------------------//
void StaticList::addItemToEndOfList(ItemType* item) //As described in the book adding items to a static list
{
	int locNew, index, prevIndex;
	
	locNew = this->m_headFree;
	this->m_headFree = this->m_array[this->m_headFree].m_next;

	if (this->m_headList == ENDLIST) //If there's no list yet set the head of the list as the head of the free list
		this->m_headList = locNew;

	else //Otherwise find tail
	{
		index = this->m_headList;

		while (index != ENDLIST)
		{
			prevIndex = index;
			index = this->m_array[index].m_next;
		}
		this->m_array[prevIndex].m_next = locNew;
	}

	//Set the computer and next is end now
	this->m_array[locNew].m_item = item;
	this->m_array[locNew].m_next = ENDLIST;
}
//-------------------------------------------------------------------------------------------//
