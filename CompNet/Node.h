#ifndef __NODE_H
#define __NODE_H

class ItemType;

class Node
{
public:
	ItemType* item;
	Node*     next;

	// C'tors
	Node(ItemType* item = nullptr, Node* next = nullptr); 
	Node(const Node&) = delete;
	Node(Node&&) = default;
	~Node() = default;
	// Methods
	void insertAfter(Node* node);
	Node* deleteAfter();
	// Setters
	void setitem(ItemType* item);
	// Getters
	ItemType* getItem() const;
	Node* getNext() const;

};

#endif // __NODE_H