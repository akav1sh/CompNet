#include "ComputerNetwork.h"

//-------------------------------------------------------------------------------------------------//
ComputerNetwork::ComputerNetwork(int sizeOfArr)
	: m_sizeOfArr(sizeOfArr), m_PCArr(nullptr), m_accessiblePCs(sizeOfArr), m_mainPC(NoPC)
{
	m_PCArr    = new ItemType[sizeOfArr];
	m_colorArr = new eCOLOR  [sizeOfArr](); // set all PCs to zero which is white.
}
//-------------------------------------------------------------------------------------------------//
ComputerNetwork::~ComputerNetwork()
{
	delete[] this->m_PCArr;
	delete[] this->m_colorArr;
}
//-------------------------------------------------------------------------------------------------//
void ComputerNetwork::setMainPC(int pc)
{
	this->m_mainPC = pc;
}
//-------------------------------------------------------------------------------------------------//
ItemType* ComputerNetwork::getPCArr()
{
	return this->m_PCArr;
}
//-------------------------------------------------------------------------------------------------//
void ComputerNetwork::findAccessible(const string& func)
{
	if (func == "Recursive")
		this->findAccessibleRec(this->m_mainPC);
	else if (func == "Iterative")
		this->findAccessibleItr(this->m_mainPC);
	else
		exit(INVALID_INPUT_ERROR);

	this->printAccessibles();
	this->m_accessiblePCs.makeEmpty();
	this->resetColorArr();
	//TODO clean all
}
//-------------------------------------------------------------------------------------------------//
void ComputerNetwork::findAccessibleRec(int mainPC)
{
	this->m_colorArr[mainPC - 1] = BLACK;
	this->m_accessiblePCs.addItemToEndOfList(&this->m_PCArr[mainPC - 1]);
	ItemType* nextConnection = this->m_PCArr[mainPC - 1].getNext();

	while(nextConnection)
	{
		int newMain = nextConnection->getPCNum();
		
		nextConnection = nextConnection->getNext();

		if(this->m_colorArr[newMain - 1] == WHITE)
			findAccessibleRec(newMain);
	}

}
//-------------------------------------------------------------------------------------------------//
void ComputerNetwork::findAccessibleItr(int mainPC)
{
	Stack stack;
	bool returnFromRecursion = false;

	ItemType* currentItem = &this->m_PCArr[mainPC - 1]; //Variable to go over the arrays and lists we have
	stack.push(currentItem);

	do
	{
		if (returnFromRecursion)
			currentItem = stack.pop();
		

		if (currentItem->getPlace() == ItemType::START)
		{

			if (this->m_colorArr[currentItem->getPCNum() - 1] == WHITE)
			{
				this->m_colorArr[currentItem->getPCNum() - 1] = BLACK;
				this->m_accessiblePCs.addItemToEndOfList(currentItem);
				currentItem->setPlace(ItemType::AFTER_FIRST);
			}

			
			else
				currentItem->setPlace(ItemType::AFTER_SECOND);

			returnFromRecursion = false;
		}

		else if (currentItem->getPlace() == ItemType::AFTER_FIRST)
		{
			if (currentItem->getNext())
			{
				while (currentItem->getNext() && this->m_colorArr[currentItem->getPCNum() - 1] == BLACK)
				{
					currentItem = currentItem->getNext();
					currentItem->setPlace(ItemType::AFTER_FIRST);
				}

				if(this->m_colorArr[currentItem->getPCNum() - 1] == BLACK)
					currentItem->setPlace(ItemType::AFTER_SECOND);

				else
				{
					stack.push(currentItem);
					currentItem = &this->m_PCArr[currentItem->getPCNum() - 1];
				}
			}


			else
				currentItem->setPlace(ItemType::AFTER_SECOND);

			returnFromRecursion = false;
		}

		else //AFTER_SECOND
			returnFromRecursion = true;

	} while (!stack.isEmpty());

}
//-------------------------------------------------------------------------------------------------//
void ComputerNetwork::printAccessibles()
{
	int next = m_accessiblePCs.getHeadList();

	while (next != ENDLIST)
	{
		cout << m_accessiblePCs.getArray()[next].getItem()->getPCNum() << ' ';
		next = m_accessiblePCs.getArray()[next].getNext();
	}
	cout << endl;
}
//-------------------------------------------------------------------------------------------------//
void ComputerNetwork::resetColorArr()
{
	delete this->m_colorArr;
	this->m_colorArr = new eCOLOR[this->m_sizeOfArr]();
}
//-------------------------------------------------------------------------------------------------//
void ComputerNetwork::checkConnectionInput(int pc1)
{
	if (pc1 <= 0 || pc1 > this->m_sizeOfArr)
	{
		cout << "no such computer " << pc1 << endl;
		exit(INVALID_INPUT_ERROR);
	}
}
