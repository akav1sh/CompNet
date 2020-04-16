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
	this->m_colorArr[mainPC - 1] = BLACK;									//start
	this->m_accessiblePCs.addItemToEndOfList(&this->m_PCArr[mainPC - 1]);
	Node* nextConnection = this->m_PCArr[mainPC - 1].getList().getHead();

	while(nextConnection)
	{
		int newMain = nextConnection->getItem()->getPCNum();
		
		nextConnection = nextConnection->getNext();

		if(this->m_colorArr[newMain - 1] == WHITE)
			findAccessibleRec(newMain);                                    // after first
	}
}
//-------------------------------------------------------------------------------------------------//
void ComputerNetwork::findAccessibleItr(int mainPC)
{
	Stack stack; // Stack which simulates the recursion.
	Node* currentNode = new Node(&this->m_PCArr[mainPC - 1]); // Values of current “recursive call”
	Node* Next; // Values of next “recursive call”.
	Node* temp = currentNode; //To delete after we used this node

	stack.push(currentNode->getItem());
	while (!stack.isEmpty()) 
	{
		currentNode->setItem(stack.pop());
		if (currentNode->getItem()->getPlace() == ItemType::START)
		{
			if (this->m_colorArr[currentNode->getItem()->getPCNum() - 1] == WHITE)
			{
				this->m_colorArr[currentNode->getItem()->getPCNum() - 1] = BLACK;
				this->m_accessiblePCs.addItemToEndOfList(currentNode->getItem());
			}
			if (currentNode->getItem()->getList().getHead() == nullptr)
			{
				currentNode->getItem()->setPlace(ItemType::AFTER_SECOND);
				stack.push(currentNode->getItem());
			}
			else 
			{
				currentNode->getItem()->setPlace(ItemType::AFTER_FIRST);
				stack.push(currentNode->getItem());
				Next = currentNode->getItem()->getList().getHead();
				stack.push(Next->getItem());
			}
		}
		else if (currentNode->getItem()->getPlace() == ItemType::AFTER_FIRST)
		{
			currentNode->getItem()->setPlace(ItemType::AFTER_SECOND);
			stack.push(currentNode->getItem());
			if (currentNode->getItem()->getList().getHead() != nullptr)
			{
				if (currentNode->getItem()->getList().getHead()->getNext() != nullptr)
				{
					Next = currentNode->getItem()->getList().getHead()->getNext();
					stack.push(Next->getItem());
				}
			}
		}
		else if (currentNode->getItem()->getPlace() == ItemType::AFTER_SECOND)
		{
			// In this case do nothing.
		}
	}
}
//{
//	Stack stack;
//	bool returnFromRecursion = false;
//
//	Node* currentNode = new Node(&this->m_PCArr[mainPC - 1]); //Variable to go over the arrays and lists we have
//	Node* temp = currentNode; //To delete after we used this node
//
//	do
//	{
// 		if (returnFromRecursion)
//			currentNode->setItem(stack.pop());
//
//		/*if (this->m_colorArr[currentNode->getItem()->getPCNum() - 1] == WHITE)
//		{
//			this->m_colorArr[currentNode->getItem()->getPCNum() - 1] = BLACK;
//			this->m_accessiblePCs.addItemToEndOfList(currentNode->getItem());
//		}*/
//
//		if (currentNode->getItem()->getPlace() == ItemType::START)
//		{
//			if (this->m_colorArr[currentNode->getItem()->getPCNum() - 1] == WHITE)
//			{
//				this->m_colorArr[currentNode->getItem()->getPCNum() - 1] = BLACK;
//				this->m_accessiblePCs.addItemToEndOfList(currentNode->getItem());
//			}
//
//			if (currentNode->getItem()->getList().getHead())
//			{
//				currentNode->getItem()->setPlace(ItemType::AFTER_FIRST);
//				stack.push(currentNode->getItem());
//				currentNode = currentNode->getItem()->getList().getHead();
//				stack.push(currentNode->getItem()); 
//				returnFromRecursion = true;
//			}
//			else
//			{
//				currentNode->getItem()->setPlace(ItemType::AFTER_SECOND);
//				returnFromRecursion = false;
//			}
//				
//		}
//		else if (currentNode->getItem()->getPlace() == ItemType::AFTER_FIRST) // AFTER_FIRST
//		{
//			if (currentNode->getItem()->getList().getHead()->getNext() == nullptr)
//			{
//				currentNode->getItem()->setPlace(ItemType::AFTER_SECOND);
//			}
//			else
//			{
//				//currentNode->getItem()->setPlace(ItemType::AFTER_FIRST);
//				currentNode = currentNode->getItem()->getList().getHead()->getNext();
//			}
//			stack.push(currentNode->getItem());
//			returnFromRecursion = false;
//		}
//		else //AFTER_SECOND
//			returnFromRecursion = true;
//
//	} while (!stack.isEmpty());
//
//	delete temp;
//}
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
