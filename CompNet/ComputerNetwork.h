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
	StaticList m_accessiblePCs;       
	int        m_mainPC;
	eCOLOR*    m_colorArr;            

public:
	//C'tors
	ComputerNetwork(int sizeOfArr);
	~ComputerNetwork();
	
	//Setters
	void setMainPC(int pc);
	
	//Getters
	ItemType* getPCArr();

	//Methods
	void findAccessible      (const string& func);
	void findAccessibleRec   (int mainPC);
	void findAccessibleItr   (int mainPC);
	void printAccessibles    ();
	void resetColorArr       ();
	void checkConnectionInput(int pc1);
};

#endif // __COMPUTERNETWORK_H