#include "DynamicList.h"

//-------------------------------------------------------------------------------------------//
DynamicList::DynamicList()
{
	this->m_head = this->m_tail = nullptr;
}
//-------------------------------------------------------------------------------------------//
DynamicList::~DynamicList()
{
	//Node *prev = this->m_head;
	//Node *curr = prev;

	////Go over the list and delete nodes
	//while (curr)
	//{
	//	prev = curr;
	//	curr = curr->getNext();
	//	delete prev;
	//}
}
//-------------------------------------------------------------------------------------------//
Node* DynamicList::getHead() const
{
	return this->m_head;
}
//-------------------------------------------------------------------------------------------//
Node* DynamicList::getTail() const
{
	return this->m_tail;
}
//-------------------------------------------------------------------------------------------//
void DynamicList::setHead(Node* head)
{
	this->m_head = head;
}
//-------------------------------------------------------------------------------------------//
void DynamicList::setTail(Node* tail)
{
	this->m_tail = tail;
}
//-------------------------------------------------------------------------------------------//
