#ifndef __LISTNODE_H
#define __LISTNODE_H

#include "Utils.h"
//Finish this class fully as intended
class PC;

class ListNode
{
public:
	PC* m_pc;
	int m_next;

	// C'tors
	ListNode(PC* pc = nullptr, int next = -1); // C'tor
	ListNode(const ListNode& other) = delete; // Disable copy c'tor
	ListNode(ListNode&&)            = delete;
	~ListNode()                     = default;
	// Setters
	void setPc(PC* pc);
	// Getters
	PC* getPc() const;
	int getNext() const;
};

#endif // __LISTNODE_H
