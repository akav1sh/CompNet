#include "PC.h"
int PC::items = 0;

PC::PC() : m_PCNum(++items)
{
}

PC::~PC()
{
	/*PC* curr = this->m_next;
	PC* next = curr;

	while (curr)
	{
		next = curr->m_next;
		delete curr;
		curr = next;
	}*/
}

const int PC::getPCNum() const
{
	return this->m_PCNum;
}

DynamicList* PC::getList() 
{
	return &this->m_list;
}

void PC::addItemToEndOfList(PC * pc)
{
	ItemType *prev = this->m_list.getHead();
	ItemType *curr = prev;
	ItemType *newItem = new ItemType(pc);


	while (curr)
	{
		if (*curr->getPC() == *pc)
		{
			return;
		}
		prev = curr;
		curr = curr->getNext();
	}

	if (!this->m_list.getHead() && !this->m_list.getTail())
	{
		this->getList()->setHead(newItem);
		this->getList()->setTail(newItem);
	}

	else
	{
		this->getList()->getTail()->setNext(newItem);
		this->getList()->setTail(newItem);
	}
}

bool PC::operator==(const PC &other) const
{
	return (this->m_PCNum == other.m_PCNum);
}
