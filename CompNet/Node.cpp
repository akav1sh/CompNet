#include "Node.h"

Node::Node(ItemType* item, Node* next) // C'tor
	: item(item), next(next)
{
}

// Insert new node after current node
void Node::insertAfter(Node* newNode)
{
	newNode->next = this->next;
	this->next = newNode;
}

// Delete node after current node
Node* Node::deleteAfter()
{
	Node* temp = this->next;

	if (this->next == nullptr) // End of the list
	{
		return nullptr;
	}

	this->next = temp->next;
	return temp;
}

void Node::setitem(ItemType* item)
{
	this->item = item;
}

ItemType* Node::getItem() const
{
	return item;
}

Node* Node::getNext() const
{
	return next;
}

