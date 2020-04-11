#include "ItemType.h"

ItemType::ItemType(PC* pc, ePlace plc, ItemType* next) : m_ptrToPc(pc), m_next(next), m_plcLine(plc)
{	
}

ItemType::ItemType(ItemType&& other)
{
	this->m_next = other.m_next;
	this->m_plcLine = other.m_plcLine;
	this->m_ptrToPc = other.m_ptrToPc;
	other.m_next = nullptr;
	other.m_ptrToPc = nullptr;
}

ItemType::~ItemType()  //TODO D'Tor
{
}

PC* ItemType::getPC() const
{
	return m_ptrToPc;
}

ItemType* ItemType::getNext() const
{
	return m_next;
}

ItemType::ePlace& ItemType::getPlace()
{
	return this->m_plcLine;
}

void ItemType::setNext(ItemType* next)
{
	this->m_next = next;
}

const ItemType& ItemType::operator=(ItemType& other)
{
	this->m_next = other.m_next;
	this->m_plcLine = other.m_plcLine;
	this->m_ptrToPc = other.m_ptrToPc;
	other.m_next = nullptr;
	other.m_ptrToPc = nullptr;
	return *this;
}

void ItemType::setPlace(const ePlace& newPlc)
{
	this->m_plcLine = newPlc;
}

void ItemType::setPC(PC* newPC)
{
	this->m_ptrToPc = newPC;
}


