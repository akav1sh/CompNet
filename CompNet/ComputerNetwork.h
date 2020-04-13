#ifndef __COMPUTERNETWORK_H
#define __COMPUTERNETWORK_H

#include "StaticList.h"
#include "Stack.h"

class ComputerNetwork
{
public:
	enum eCOLOR { WHITE, BLACK };

private:
	ItemType*  m_PCArr;
	const int  m_sizeOfArr;
	StaticList m_accessiblePCs;       //Clean at end of func
	int        m_mainPC;
	eCOLOR*    m_colorArr;            //Clean at end of func

public:
	//C'tors
	ComputerNetwork(int sizeOfArr);
	
	//Setters
	void setMainPC(int pc);
	
	//Getters
	ItemType* getPCArr();

	//Methods
	void findAccessible    (const string& func);
	void findAccessibleRec (int mainPC);
	void findAccessibleItr (int mainPC);
	void printAccessibles  ();
};

#endif // __COMPUTERNETWORK_H