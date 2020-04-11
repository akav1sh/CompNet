#ifndef __COMPUTERNETWORK_H
#define __COMPUTERNETWORK_H

#include "StaticList.h"
#include "PC.h"
#include "Stack.h"
#include "DynamicList.h"

class ComputerNetwork
{
private:
	PC* m_PCArr;
	const int m_sizeOfArr;
	StaticList m_accessiblePCs;       //Clean at end of func
	int  m_mainPC;
	enum eCOLOR {WHITE, BLACK};
	eCOLOR* m_colorArr;         //Clean at end of func

public:
	ComputerNetwork(int sizeOfArr);
	//Setters
	void setMainPC(int pc);
	//Getters
	PC* getPCArr();

	//Methods
	void findAccessible(const string& func);
	void findAccessibleRec(int mainPC);
	void findAccessibleItr(int mainPC);
	void printAccessibles();



};

#endif // __COMPUTERNETWORK_H