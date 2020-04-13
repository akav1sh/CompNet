#ifndef __ITEMTYPE_H
#define __ITEMTYPE_H

#include "Utils.h"
#include "Node.h"
class PC;

//Class as requested in the assignment 
class ItemType
{
public:
	enum ePlace { START, AFTER_FIRST };

private:
	ePlace    m_plcLine; //To know our place in line of the non recursive function
	PC*       m_pc;      //Pointer to a computer in the pc network
	ItemType* m_next; ///Want to delete next

public:
	// C'tors
	 ItemType(PC* pc = nullptr, ePlace plc = START, ItemType* next = nullptr);
	 ItemType(const ItemType&) = delete;
	 ItemType(ItemType&& other);
	~ItemType(); /// create with deletion of nodes

	//Getters
	PC*       getPC    () const;
	ItemType* getNext  () const; 
	ePlace&   getPlace ();

	//Setters
	void setNext  (ItemType* next);
	void setPlace (const ePlace& newPlc);
	void setPC    (PC* newPC);

	//Operators
	const ItemType& operator=(ItemType&& other);

};
#endif // __ITEMTYPE_H