#include "ItemType.h"

//-------------------------------------------------------------------------------------------//
ItemType::ItemType(PC* pc, ePlace plc, ItemType* next) : m_pc(pc), m_next(next), m_plcLine(plc)
{	
}
//-------------------------------------------------------------------------------------------//
ItemType::ItemType(ItemType&& other)
{
	this->m_next    = other.m_next;
	this->m_plcLine = other.m_plcLine;
	this->m_pc      = other.m_pc;
	other.m_next    = nullptr;
	other.m_pc      = nullptr;
}
//-------------------------------------------------------------------------------------------//
ItemType::~ItemType()  //TODO D'Tor
{
}
//-------------------------------------------------------------------------------------------//
PC* ItemType::getPC() const
{
	return this->m_pc;
}
//-------------------------------------------------------------------------------------------//
ItemType* ItemType::getNext() const
{
	return this->m_next;
}
//-------------------------------------------------------------------------------------------//
ItemType::ePlace& ItemType::getPlace()
{
	return this->m_plcLine;
}
//-------------------------------------------------------------------------------------------//
void ItemType::setNext(ItemType* next)
{
	this->m_next = next;
}
//-------------------------------------------------------------------------------------------//
void ItemType::setPlace(const ePlace& newPlc)
{
	this->m_plcLine = newPlc;
}
//-------------------------------------------------------------------------------------------//
void ItemType::setPC(PC* newPC)
{
	this->m_pc = newPC;
}
//-------------------------------------------------------------------------------------------//
const ItemType& ItemType::operator=(ItemType&& other)
{
	this->m_next    = other.m_next;
	this->m_plcLine = other.m_plcLine;
	this->m_pc      = other.m_pc;
	other.m_next    = nullptr;
	other.m_pc      = nullptr;
	return *this;
}
//-------------------------------------------------------------------------------------------//
