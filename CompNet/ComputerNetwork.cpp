#include "ComputerNetwork.h"

//-------------------------------------------------------------------------------------------------//
ComputerNetwork::ComputerNetwork(int sizeOfArr)
	: m_sizeOfArr(sizeOfArr), m_PCArr(nullptr), m_accessiblePCs(sizeOfArr), m_mainPC(NULL)
{
	m_PCArr    = new ItemType[sizeOfArr];
	m_colorArr = new eCOLOR  [sizeOfArr](); // set all PCs to zero which is white.
}
//-------------------------------------------------------------------------------------------------//
ComputerNetwork::~ComputerNetwork()
{
	delete this->m_PCArr;
	delete this->m_colorArr;
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
	Node* nextConnection = this->m_PCArr[mainPC - 1].getList().getHead();

	while(nextConnection)
	{
		int newMain = nextConnection->getItem()->getPCNum();
		
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

	Node* currentNode = new Node(&this->m_PCArr[mainPC - 1]);

	do
	{
		if (returnFromRecursion)
			currentNode->setItem(stack.pop());

		if (this->m_colorArr[currentNode->getItem()->getPCNum() - 1] == WHITE)
		{
			this->m_colorArr[currentNode->getItem()->getPCNum() - 1] = BLACK;
			this->m_accessiblePCs.addItemToEndOfList(currentNode->getItem());
		}

		if (currentNode->getItem()->getPlace() == ItemType::START)
		{
			currentNode->getItem()->setPlace(ItemType::AFTER_FIRST);
			if (currentNode->getItem()->getList().getHead())
			{
				currentNode = currentNode->getItem()->getList().getHead();
				returnFromRecursion = true;
				stack.push(currentNode->getItem()); //Maybe stack should take node
			}
			else
				returnFromRecursion = false;
		}
		else // AFTER_FIRST
		{
			if (currentNode->getNext() == nullptr)
			{
				currentNode->getItem()->setPlace(ItemType::START);
			}
			else
			{
				currentNode->getItem()->setPlace(ItemType::AFTER_FIRST);
				currentNode = currentNode->getNext();
			}
			returnFromRecursion = true;
			stack.push(currentNode->getItem());
		}
	} while (!stack.isEmpty());

	delete currentNode;
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
