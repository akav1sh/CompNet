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

	Node* currentNode = new Node(&this->m_PCArr[mainPC - 1]); //Variable to go over the arrays and lists we have
	Node* nodeToDelete = currentNode; //To delete after we used this node

	do
	{
 		if (returnFromRecursion)
			currentNode->setItem(stack.pop());

		if (currentNode->getItem()->getPlace() == ItemType::START)
		{
			if (this->m_colorArr[currentNode->getItem()->getPCNum() - 1] == WHITE)
			{
				this->m_colorArr[currentNode->getItem()->getPCNum() - 1] = BLACK;
				this->m_accessiblePCs.addItemToEndOfList(currentNode->getItem());
			}

			currentNode->getItem()->setPlace(ItemType::AFTER_FIRST);
			stack.push(currentNode->getItem());

			if (currentNode->getNext() && !currentNode->getItem()->getList().getHead())
			{
				currentNode->setItem(currentNode->getNext()->getItem());
				currentNode->setNext(currentNode->getNext()->getNext());
			}

			else
				currentNode->getItem()->setPlace(ItemType::AFTER_FIRST);
			

			returnFromRecursion = false;
		}

		else if (currentNode->getItem()->getPlace() == ItemType::AFTER_FIRST) // AFTER_FIRST
		{
			
			if (currentNode->getItem()->getList().getHead())
			{
					Node* nodeToInsertToStack = currentNode->getNext();

					while (nodeToInsertToStack)
					{
						stack.push(nodeToInsertToStack->getItem());
						nodeToInsertToStack = nodeToInsertToStack->getNext();
					}

				if (this->m_colorArr[currentNode->getItem()->getList().getHead()->getItem()->getPCNum() - 1] == WHITE)
				{
					currentNode->setNext(currentNode->getItem()->getList().getHead()->getNext());
					currentNode->setItem(currentNode->getItem()->getList().getHead()->getItem());

					returnFromRecursion = false;
				}

				else
					returnFromRecursion = true;
			}

			else
			{
				currentNode->getItem()->setPlace(ItemType::AFTER_SECOND);
				returnFromRecursion = false;
			}
		}

		else //AFTER_SECOND
			returnFromRecursion = true;
		

	} while (!stack.isEmpty());

	delete nodeToDelete;
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
