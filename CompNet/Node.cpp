#include "Node.h"
//-------------------------------------------------------------------------------------------//
Node::Node(ItemType* item, Node* next) // C'tor
	: m_item(item), m_next(next)
{
}
//-------------------------------------------------------------------------------------------//
void Node::setitem(ItemType* item)
{
	this->m_item = item;
}
//-------------------------------------------------------------------------------------------//
ItemType* Node::getItem() const
{
	return this->m_item;
}
//-------------------------------------------------------------------------------------------//
Node* Node::getNext() const
{
	return this->m_next;
}
//-------------------------------------------------------------------------------------------//
// Insert new node after current node
void Node::insertAfter(Node* newNode)
{
	newNode->m_next = this->m_next;
	this->m_next    = newNode;
}
//-------------------------------------------------------------------------------------------//
// Delete node after current node
Node* Node::deleteAfter()
{
	Node* temp = this->m_next;

	if (!this->m_next) // End of the list
	{
		return nullptr;
	}

	this->m_next = temp->m_next;
	return temp;
}
//-------------------------------------------------------------------------------------------//
