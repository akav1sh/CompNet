#include "DynamicList.h"

DynamicList::DynamicList()
{
	this->m_head = this->m_tail = nullptr;
}

DynamicList::~DynamicList()
{
}

ItemType * DynamicList::getHead() const
{
	return this->m_head;
}

ItemType * DynamicList::getTail() const
{
	return this->m_tail;
}

void DynamicList::setHead(ItemType* head)
{
	this->m_head = head;
}

void DynamicList::setTail(ItemType * tail)
{
	this->m_tail = tail;
}

