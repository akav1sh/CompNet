#include "Stack.h"

//-------------------------------------------------------------//
Stack::Stack() // C'tor
	: m_topOfStack(nullptr)
{
}
//-------------------------------------------------------------//
Stack::~Stack() // D'tor
{
	this->makeEmpty();
}
//-------------------------------------------------------------//
// Make an empty stack
void Stack::makeEmpty()
{
	Node* temp;

	while (this->m_topOfStack)
	{
		temp = this->m_topOfStack;
		this->m_topOfStack = this->m_topOfStack->getNext();
		delete temp;
	}
}
//-------------------------------------------------------------//
// Check if stack is empty
bool Stack::isEmpty() const
{
	return (this->m_topOfStack == nullptr);
}
//-------------------------------------------------------------//
// Push m_item into the stack
void Stack::push(ItemType* m_item)
{
	this->m_topOfStack = new Node(m_item, m_topOfStack);
}
//-------------------------------------------------------------//
// Pop top m_item and return it
ItemType* Stack::pop()
{
	if (isEmpty())
	{
		cout << "Error: Stack is empty!" << endl;
		exit(EMPTY_STACK_ERROR);
	}

	Node*     tempNode = this->m_topOfStack;
	ItemType* tempItem = tempNode->getItem();
	this->m_topOfStack = this->m_topOfStack->getNext();

	delete tempNode;
	return tempItem;
}
//-------------------------------------------------------------//
// Return the data of the top m_item in the stack
ItemType* Stack::top() const
{
	if (isEmpty())
	{
		cout << "Error: Stack is empty!" << endl;
		exit(EMPTY_STACK_ERROR);
	}

	return this->m_topOfStack->getItem();
}
//-------------------------------------------------------------//
