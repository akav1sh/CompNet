#ifndef __PC_H
#define __PC_H

#include "Utils.h"
#include "DynamicList.h"

class PC
{
private:
	DynamicList  m_list;
	const int    m_PCNum;
	static int   items;

public:
	// C'tors
	 PC(); 
 	 PC(const PC&) = delete;
 	 PC(PC&&)      = delete;
	 ~PC(); // create with deletion of nodes
	// Getters
	const int getPCNum() const;
	DynamicList* getList();

	//Methods
	void addItemToEndOfList(PC* pc);

	// Operators
	bool operator==(const PC &other) const;

};
#endif // __PC_H