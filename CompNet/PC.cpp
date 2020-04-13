#include "PC.h"

int PC::items = 0;
//-------------------------------------------------------------------------------------------//
//Constructor
PC::PC() : m_PCNum(++items)
{
}
//-------------------------------------------------------------------------------------------//
//Destructor
PC::~PC()
{
	ItemType *prev = this->m_list.getHead();
	ItemType *curr = prev;

	//Loop to go through connection list amd delete all allocated nodes
	while (curr)
	{
		prev = curr;
		curr = curr->getNext();

		delete prev;
	}

	delete prev;
}
//-------------------------------------------------------------------------------------------//
const int PC::getPCNum() const
{
	return this->m_PCNum;
}
//-------------------------------------------------------------------------------------------//
DynamicList& PC::getList()
{
	return this->m_list;
}
//-------------------------------------------------------------------------------------------//
//Function adds m_item to end of the connections list, done in this class because
//of include issues in dynamic list class
void PC::addItemToEndOfList(PC* pc)
{
	ItemType *prev = this->m_list.getHead();
	ItemType *curr = prev;

	//Go over the connection list
	while (curr)
	{
		//If this computer is already on the list, return
		if (*curr->getPC() == *pc)
		{
			return;
		}
		prev = curr;
		curr = curr->getNext();
	}

	//Create and add the computer to the list
	ItemType *newItem = new ItemType(pc);

	if (!this->m_list.getHead() && !this->m_list.getTail()) //Both head and tail are nullptr
	{
		this->getList().setHead(newItem);
		this->getList().setTail(newItem);
	}

	else
	{
		this->getList().getTail()->setNext(newItem);
		this->getList().setTail(newItem);
	}
}
//-------------------------------------------------------------------------------------------//
bool PC::operator==(const PC &other) const
{
	return (this->m_PCNum == other.m_PCNum);
}
//-------------------------------------------------------------------------------------------//
