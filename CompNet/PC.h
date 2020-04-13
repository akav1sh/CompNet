#ifndef __PC_H
#define __PC_H

#include "Utils.h"
#include "DynamicList.h"

//Class that holds the compters in the computer network array
class PC
{
private:
	static int  items;   //Item counter, static variable to appoint as computer number

	DynamicList m_list;  //List of all the connections of this computer
	const int   m_PCNum; //This computer's appointed number

public:
	// C'tors, no copy or move
	  PC(); 
 	  PC(const PC&) = delete;
 	  PC(PC&&)      = delete;
	 ~PC();
	// Getters
	const int    getPCNum() const;
	DynamicList& getList ();

	// Methods
	void addItemToEndOfList(PC* pc);

	// Operators
	bool operator==(const PC &other) const;
};
#endif // __PC_H