#include "ItemType.h"
int ItemType::items = 0;
//-------------------------------------------------------------------------------------------//
ItemType::ItemType(ePlace plc) : m_PCNum(++items), m_plcLine(plc)
{	
}
//-------------------------------------------------------------------------------------------//
ItemType::~ItemType()  //TODO D'Tor
{
	//Delete nodes 
}
//-------------------------------------------------------------------------------------------//
ItemType::ePlace& ItemType::getPlace()
{
	return this->m_plcLine;
}
//-------------------------------------------------------------------------------------------//
void ItemType::setPlace(const ePlace& newPlc)
{
	this->m_plcLine = newPlc;
}
//-------------------------------------------------------------------------------------------//
bool ItemType::operator==(const ItemType & other) const
{
	return (this->m_PCNum == other.m_PCNum);
}
//-------------------------------------------------------------------------------------------//
const int ItemType::getPCNum() const
{
	return this->m_PCNum;
}
//-------------------------------------------------------------------------------------------//
DynamicList& ItemType::getList()
{
	return this->m_list;
}
//-------------------------------------------------------------------------------------------//
void ItemType::addItemToEndOfList(ItemType* item)
{
	Node *prev = this->m_list.getHead();
	Node *curr = prev;

	//Go over the connection list
	while (curr)
	{
		//If this computer is already on the list, return
		if (*curr->getItem() == *item)
		{
			return;
		}
		prev = curr;
		curr = curr->getNext();
	}

	//Create and add the computer to the list
	Node *newItem = new Node(item);

	if (!this->m_list.getHead() && !this->m_list.getTail()) //Both head and tail are nullptr
	{
		this->getList().setHead(newItem);
		this->getList().setTail(newItem);
	}

	else
	{
		this->getList().getTail()->insertAfter(newItem);
		this->getList().setTail(newItem);
	}
}
//-------------------------------------------------------------------------------------------//
