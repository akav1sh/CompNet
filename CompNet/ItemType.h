#ifndef __ITEMTYPE_H
#define __ITEMTYPE_H

#include "Utils.h"
//#include "DynamicList.h"

//Class as requested in the assignment 
class ItemType
{
public:
	enum ePlace { START, AFTER_FIRST, AFTER_SECOND };

private:
	ePlace      m_plcLine; //To know our place in line of the non recursive function
	//DynamicList m_list;    //List of all the connections of this computer
	const int   m_PCNum;   //This computer's appointed number
	ItemType*   m_next;
	static int  items;   //Item counter, static variable to appoint as computer number

public:
	// C'tors
	 ItemType( ePlace plc = START);
	 ItemType(const ItemType& other);
	 ItemType(ItemType&& other) = default;
	~ItemType(); /// create with deletion of nodes

	//Getters
	ePlace&      getPlace ();
	const int    getPCNum () const;
	//DynamicList& getList  ();
	ItemType*   getNext();

	//Setters
	void setPlace (const ePlace& newPlc);
	void setNext(ItemType* next);
	// Methods
	void addItemToEndOfList(ItemType* pc);

	//Operators
	bool operator==(const ItemType &other) const;

};
#endif // __ITEMTYPE_H