/*
Brett Hiebert
BinNode.h
BinNode Template Class Declaration
Data Members: BinNode has a "data" datafield and a "left" and "right" BinNode pointer to point to its children.
9/2018
*/

#ifndef BINNODE_H
#define BINNODE_H

template <class Item>
class BinNode
{
public:

	//DEFAULT CONSTRUCTOR - Note: Default args set the init data and allow for input so only the default is needed.
	BinNode(const Item& initData = Item(), BinNode* initLeft = nullptr, BinNode* initRight = nullptr);

	//GETTERS - Note: Since BinaryTree is a friend function and members are accessed directly these are not used, but are included for class completeness.
	Item& getData() { return data; }
	BinNode*& getLeft() { return left; }
	BinNode*& getRight() { return right; }

	//CONST GETTERS - Note: Not used in BinaryTree but included here for class completeness.
	const Item& getData() const { return data; }
	const BinNode*& getLeft() const { return left; }
	const BinNode*& getRight() const { return right; }

	//SETTERS - Note: Not used in BinaryTree but included here for class completeness.
	void setData(const Item& entry) { data = entry; }
	void setLeft(BinNode* leftIn) { left = leftIn; }
	void setRight(BinNode* rightIn) { left = rightIn; }

	//OTHER MEMBER FUNCTIONS
	bool isLeaf() const;

private:
	Item data;
	BinNode* left;
	BinNode* right;
	template <class I> friend class BinaryTree; // BinaryTree is a friend class so private data members can be accessed directly.					
};

#include "BinNode.tem"

#endif
