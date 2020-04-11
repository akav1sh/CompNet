#include "Stack.h"

Stack::Stack() // C'tor
	: topOfStack(nullptr)
{
}

Stack::~Stack() // D'tor
{
	makeEmpty();
}

// Make an empty stack
void Stack::makeEmpty()
{
	Node* temp;

	while (topOfStack != nullptr)
	{
		temp = topOfStack;
		topOfStack = topOfStack->getNext();
		delete temp;
	}
}

// Check if stack is empty
bool Stack::isEmpty() const
{
	return (topOfStack == nullptr);
}

// Push item into the stack
void Stack::push(ItemType* item)
{
	topOfStack = new Node(item, topOfStack);
}

// Pop top item and return it
ItemType* Stack::pop()
{
	if (isEmpty())
	{
		cout << "Error: Stack is empty!" << endl;
		exit(EMPTY_STACK_ERROR);
	}
	Node* tempNode = topOfStack;
	ItemType* temp = tempNode->getItem();
	topOfStack = topOfStack->getNext();

	delete tempNode;
	return temp;
}

// Return the data of the top item in the stack
ItemType* Stack::top() const
{
	if (isEmpty())
	{
		cout << "Error: Stack is empty!" << endl;
		exit(EMPTY_STACK_ERROR);
	}

	return topOfStack->getItem();
}