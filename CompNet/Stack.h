#ifndef __STACK_H
#define __STACK_H

#include "ItemType.h"

// Stack who's data are ItemTypes and uses nodes for next in line
class Stack
{
private:
	Node* m_topOfStack; // Pointer node to the top of the stack

public:
	// C'tors, no copy or move
	 Stack();
	 Stack(const Stack&) = delete;
	 Stack(Stack&&)      = delete;
	~Stack();

	// Stack methods
	void makeEmpty ();
	bool isEmpty   () const;
	void push      (ItemType* item);
	ItemType* pop  ();
	ItemType* top  () const;
};

#endif // __STACK_H