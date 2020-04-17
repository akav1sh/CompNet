#include "ItemType.h"
int ItemType::items = 0;
//-------------------------------------------------------------------------------------------//
ItemType::ItemType(ePlace plc) : m_PCNum(++items), m_plcLine(plc), m_next(nullptr) //C'tor
{	
}
//-------------------------------------------------------------------------------------------//
ItemType::ItemType(const ItemType& other) : m_PCNum(other.m_PCNum) //Copy c'tor
{
	this->m_plcLine = other.m_plcLine;
	this->m_next = nullptr;
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
void ItemType::setNext(ItemType * next)
{
	this->m_next = next;
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
ItemType* ItemType::getNext()
{
	return this->m_next;
}
//-------------------------------------------------------------------------------------------//
void ItemType::addItemToEndOfList(ItemType* item)
{
	if (this->m_PCNum == item->m_PCNum)
		return;

	ItemType *prev = this->m_next;
	ItemType *curr = prev;

	//Go over the connection list
	while (curr)
	{
		//If this computer is already on the list, return
		if (*curr == *item)
		{
			return;
		}
		prev = curr;
		curr = curr->m_next;
	}

	//Create and add the computer to the list
	if (prev)
		prev->m_next = item;
	else
		this->m_next = item;

}
//-------------------------------------------------------------------------------------------//
