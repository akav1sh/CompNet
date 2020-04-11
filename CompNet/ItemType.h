#ifndef __ITEMTYPE_H
#define __ITEMTYPE_H

#include "Utils.h"
#include "Node.h"
class PC;

class ItemType
{
public:
	enum ePlace { START, AFTER_FIRST };

private:
	ePlace    m_plcLine;
	PC*       m_ptrToPc;
	ItemType* m_next;

public:
	// C'tors
	ItemType(PC* pc = nullptr, ePlace plc = START, ItemType* next = nullptr);
	ItemType(const ItemType&) = delete;
	ItemType(ItemType&& other);
	~ItemType(); // create with deletion of nodes

	//Getters
	PC* getPC() const;
	ItemType* getNext() const; 
	ePlace& getPlace();

	//Setters
	void setNext(ItemType* next);
	void setPlace(const ePlace& newPlc);
	void setPC(PC* newPC);

	//Operators
	const ItemType& operator=(ItemType& other);

};
#endif // __ITEMTYPE_H