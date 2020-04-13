#ifndef __STATICLIST_H
#define __STATICLIST_H

#include "Utils.h"

class PC;

//List as asked in the assignment, static with an array that we allocate dynamically in size requested
class StaticList
{
private:
	//Nested node class
	class ListNode
	{
	private:
		friend class StaticList;

		PC* m_pc;
		int m_next;

		 ListNode(PC* pc = nullptr, int next = -1) : m_pc(pc), m_next(next) {}
		 ListNode(const ListNode& other)     = delete; // Disable copy c'tor
		 ListNode(ListNode&&)                = delete;
		~ListNode()                          = default;

	public:
		PC* getPC   () const { return m_pc;   }
		int getNext () const { return m_next; }
	};

private:
	ListNode*  m_array;    //Static array
	int        m_headList; //Head of the actual list
	int        m_headFree; //Head of the free empty list
	int        m_size;     //Size of the array

public:
	// C'tors
	 StaticList(int size);
	 StaticList(const StaticList&) = delete;
	 StaticList(StaticList&&)      = delete;
	~StaticList();

	//Getters
	ListNode* getArray    ();
	int       getHeadList ();
	int       getHeadFree ();
	int       getSize     ();

	// Methods
	void addItemToEndOfList(PC* pc);
};

#endif // __STATICLIST_H
