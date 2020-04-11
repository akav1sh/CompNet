#include "StaticList.h"

StaticList::StaticList(int size) : m_size(size)
{
	this->m_array = new ListNode[size];
	int i;
	for (i = 0; i < size - 1; ++i)
	{
		this->m_array[i].m_next = i + 1;
	}
	this->m_array[i].m_next = ENDLIST;
	this->m_headFree =  0;
	this->m_headList = ENDLIST;
}

StaticList::~StaticList()
{
	delete this->m_array;
}

ListNode * StaticList::getArray()
{
	return m_array;
}

int StaticList::getHeadList()
{
	return m_headList;
}

int StaticList::getHeadFree()
{
	return m_headFree;
}

int StaticList::getSize()
{
	return m_size;
}

void StaticList::addItemToEndOfList(PC* pc)
{
	int locNew, index, prevIndex;
	
	locNew = this->m_headFree;
	this->m_headFree = this->m_array[this->m_headFree].m_next;

	if (this->m_headList == ENDLIST)
		this->m_headList = locNew;
	else
	{
		index = this->m_headList;

		while (index != ENDLIST)
		{
			prevIndex = index;
			index = this->m_array[index].m_next;
		}
		this->m_array[prevIndex].m_next = locNew;
	}

	this->m_array[locNew].m_pc = pc;
	this->m_array[locNew].m_next = ENDLIST;
	
}
