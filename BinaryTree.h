/*
Brett Hiebert
BinaryTree.h
BinaryTree Template Class Declaration
Data Members: BinaryTree has a BinNode pointer "root" and a std::size_t "treeSize" member for keeping track of the total tree size.
9/25/2018
*/

#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include <iostream>
#include <fstream>
#include <string>
#include "BinNode.h"

template <class Item>
class BinaryTree
{
public:

	//CONSTRUCTOR
	BinaryTree();

	//COPY CONSTRUCTOR
	BinaryTree(const BinaryTree& source);

	//ASSIGNMENT OPERATOR OVERLOAD
	void operator =(const BinaryTree& source);

	//DESTRUCTOR
	~BinaryTree();

	//GETTERS
	std::size_t countItems() const { return treeSize; } //Note: TreeSize is tracked in the add, remove, clear, and copy functions. This returns the current tree size.
	void printAll(); // Note: This prints out the data in-order with the number and tree depth of each entry.
	void printAsTree(const int DATA_SPACING_IN = 15); // Note: I included this special print function. It is very usefully for debugging and visualizing the trees. The optional argument is for specifying the space given for the data fields (default at 15).

	//SETTERS (MODIFICATION MEMBER FUNCTIONS)
	void add(const Item& entry); // Allocates a BinNode and places it in the tree. The item class must have <>= defined.
	bool remove(const Item& target); // Removes an item from the tree by using recursive helper functions
	void clear(); // Note: Public function for clearing a tree.

	//TRAVERSAL FUNCTION
	void inOrderTraverse(void process(Item&,int,int)); // Note: Allows public access to traverse the tree in-order and apply a process to any item in the tree. Process structure is process(data, number, depth); 

	//OTHER MEMBER FUNCTIONS
	void readFile(std::string fileName); // Note: Calls the add function to reconstruct a BinaryTree from data in a file.
	void writeFile(std::string fileName, std::string delim = " "); // Note: Writes the whole tree's data into a file starting with the root node.

private:
	BinNode<Item>* root;
	std::size_t treeSize;

	//COPY CONSTRUCTOR AND ASSIGNMENT HELPER FUNCTION
	BinNode<Item>* _copyTree(const BinNode<Item>* rootIn); // Note: Post-order recursive function for copying a tree.

	//ADD HELPER FUNCTION
	BinNode<Item>* _allocBinNode(Item entry); // Note: Allocates a single node

	//CLEAR AND DESTRUCTOR HELPER FUNCTION
	void _freeAllBinNodes(BinNode<Item>* rootIn); // Note: Destroys all of the nodes on the heap.

	//REMOVE HELPER FUNCTIONS
	bool _treeRemove(BinNode<Item>*& rootIn, const Item& target, BinNode<Item>*& parentIn); // Note: This is a recursive function to remove Items from the tree. It covers the 2 easiest cases for node removal (0 and 1 child);
	void _treeRemoveMax(BinNode<Item>*& rootIn, Item& target, BinNode<Item>*& parentIn); // Note: Finds and copies the max value in the left subtree into the curent node and then calls the treeRemove function to remove the duplicate.

	//PRINT HELPER FUNCTIONS
	void _print(BinNode<Item>* cursor, int& counter, int depth = 0); // Note: This is an in-order print that includes numbering and the depth an item is in the tree.
	void _printAsTree(BinNode<Item>* cursor, const int DATA_SPACING = 15, int space = 0, int depth = 0); // Note: I included this special print function. It is very usefully for debugging and visualizing the trees.  

	//FIND HELPER FUNCTIONS
	BinNode<Item>* _find(BinNode<Item>* rootIn, Item target); // Note: Not used but included for class completeness.
	Item _findMin(const BinNode<Item>* rootIn); // Note: Not used but included for class completeness.
	Item _findMax(const BinNode<Item>* rootIn); // Note: Used to find the max value in the left subtree when removing.

	//WRITEFILE HELPER FUNCTION
	void _writeFile(BinNode<Item>* rootIn, std::ofstream& fileStream, std::string delim); // Note: Pre-Order recursive function for writing data to a file. Pre-order ensures that the root data stays the same.

	//IN_ORDER TRAVERSAL HELPER FUNCTION
	void _inOrderTraverse(void process(Item&, int, int), BinNode<Item> *rootPtr, int & counter, int depth = 0); // Note: I tweaked the process structure slightly to expose a tree depth parameter (this may be useful for certain processes - i.e. reorganizing the tree...etc)
	//Note: In future development it might make sense to include all the order traversals for use outside of the class. 
	//		If the traversals are included as non-member function in the template you could even specify unique return types on the process, 
	//		but you would have to expose these private functions publicly.
};

#include "BinaryTree.tem"

#endif
