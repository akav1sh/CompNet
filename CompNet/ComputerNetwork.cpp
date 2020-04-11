#include "ComputerNetwork.h"

ComputerNetwork::ComputerNetwork(int sizeOfArr)
	: m_sizeOfArr(sizeOfArr), m_PCArr(nullptr), m_accessiblePCs(sizeOfArr), m_mainPC(NULL)
{
	m_PCArr = new PC[sizeOfArr];
	m_colorArr = new eCOLOR[sizeOfArr](); // set all PCs to zero which is white.
}

void ComputerNetwork::setMainPC(int pc)
{
	m_mainPC = pc;
}

PC* ComputerNetwork::getPCArr()
{
	return this->m_PCArr;
}

void ComputerNetwork::findAccessible(const string& func)
{
	if (func == "Recursive")
		this->findAccessibleRec(this->m_mainPC);
	else if (func == "Iterative")
		this->findAccessibleItr(this->m_mainPC);
	else
		exit(INVALID_INPUT_ERROR);

	//TODO clean all
}

void ComputerNetwork::findAccessibleRec(int mainPC)
{
	this->m_colorArr[mainPC - 1] = BLACK;
	this->m_accessiblePCs.addItemToEndOfList(&this->m_PCArr[mainPC - 1]);
	ItemType* nextConnection = this->m_PCArr[mainPC - 1].getList()->getHead();

	while(nextConnection)
	{
		int newMain = nextConnection->getPC()->getPCNum();
		
		nextConnection = nextConnection->getNext();

		if(this->m_colorArr[newMain - 1] == WHITE)
			findAccessibleRec(newMain);

	}
}

void ComputerNetwork::findAccessibleItr(int mainPC)
{
	Stack stack;
	bool returnFromRecursion = false;

	ItemType* currentItem = new ItemType(&this->m_PCArr[mainPC - 1]);

	do
	{
		if (returnFromRecursion)
			currentItem = stack.pop();

		if (this->m_colorArr[currentItem->getPC()->getPCNum() - 1] == WHITE)
		{
			this->m_colorArr[currentItem->getPC()->getPCNum() - 1] = BLACK;
			this->m_accessiblePCs.addItemToEndOfList(currentItem->getPC());
		}

		if (currentItem->getPlace() == ItemType::START)
		{
			currentItem->setPlace(ItemType::AFTER_FIRST);
			if (currentItem->getPC()->getList()->getHead())
			{
				currentItem->setPC(currentItem->getPC()->getList()->getHead()->getPC());
				returnFromRecursion = true;
				stack.push(currentItem);
			}
			else
				returnFromRecursion = false;
		}
		else // AFTER_FIRST
		{
			if (currentItem->getNext() == nullptr)
			{
				currentItem->setPlace(ItemType::START);
			}
			else
			{
				currentItem->setPlace(ItemType::AFTER_FIRST);
				currentItem->setPC(currentItem->getNext()->getPC());
			}
			returnFromRecursion = true;
			stack.push(currentItem);
		}
	} while (!stack.isEmpty());
}

void ComputerNetwork::printAccessibles()
{
	int next = m_accessiblePCs.getHeadList();

	while (next != ENDLIST)
	{
		cout << m_accessiblePCs.getArray()[next].m_pc->getPCNum() << ' ';
		next = m_accessiblePCs.getArray()[next].m_next;
	}
}
