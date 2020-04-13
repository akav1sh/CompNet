#ifndef __NODE_H
#define __NODE_H

class ItemType;

//Node class for stack
class Node
{
private:
	ItemType* m_item; //Data in this node
	Node*     m_next; //Next one in line

public:
	// C'tors
	 Node(ItemType* item = nullptr, Node* next = nullptr); 
	 Node(const Node&)   = delete;
	 Node(Node&&)        = default;
	~Node()              = default;
	
	// Setters
	void setItem (ItemType* item);

	// Getters
	ItemType* getItem() const;
	Node*     getNext() const;

	// Methods
	void  insertAfter(Node* node);
	Node* deleteAfter();
};

#endif // __NODE_H