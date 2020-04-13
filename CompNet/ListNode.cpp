#include "ListNode.h"

ListNode::ListNode(PC* pc, int next) // C'tor
	: m_pc(pc), m_next(next)
{
}

void ListNode::setPC(PC* pc)
{
	this->m_pc = pc;
}

PC* ListNode::getPc() const
{
	return m_pc;
}

int ListNode::getNext() const
{
	return m_next;
}