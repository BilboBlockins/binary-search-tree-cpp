/*
Brett Hiebert
This is a test program for the BinaryTree class. 
It tests various member functions, as well as an in-order traversal function that applies a user defined function to every item in the tree.
9/25/2018
*/

#include "BinaryTree.h"

//User defined template function declaration for modifying data in the tree.
template <class Item>
void doubleMyData(Item& data, int number, int depth);

int main()
{
	BinaryTree<int> intTree;
	BinaryTree<double> doubleTree;
	BinaryTree<std::string> stringTree;

	std::cout << "INT BINARYTREE" << std::endl;
	std::cout << "==========================================================" << std::endl;
	intTree.readFile("IntTest.dat");
	std::cout << "\nThere are " << intTree.countItems() << " nodes in the INT tree.\n" << std::endl;
	intTree.printAll();
	std::cout << "\n";

	intTree.add(3);
	intTree.add(0);
	intTree.remove(14);

	std::cout << "\nNow there are " << intTree.countItems() << " nodes in the INT tree." << std::endl;

	std::cout << "\n";
	intTree.printAsTree();
	std::cout << "\n";

	std::cout << "DOUBLE BINARYTREE" << std::endl;
	std::cout << "==========================================================" << std::endl;
	doubleTree.readFile("DoubleTest.dat");
	std::cout << "\nThere are " << doubleTree.countItems() << " nodes in the DOUBLE tree.\n" << std::endl;
	doubleTree.printAll();
	std::cout << "\n";

	doubleTree.add(9.9);
	doubleTree.add(18.8);
	doubleTree.remove(1.1);

	std::cout << "\nNow there are " << doubleTree.countItems() << " nodes in the DOUBLE tree." << std::endl;

	std::cout << "\n";
	doubleTree.printAsTree();
	std::cout << "\n";

	std::cout << "STRING BINARYTREE" << std::endl;
	std::cout << "==========================================================" << std::endl;
	stringTree.readFile("StringTest.dat");
	std::cout << "\nThere are " << stringTree.countItems() << " nodes in the STRING tree.\n" << std::endl;
	stringTree.printAll();
	std::cout << "\n";

	stringTree.add("although"); // these are sorted alphabetically
	stringTree.add("it's");
	stringTree.add("been");
	stringTree.add("said");
	stringTree.add("many");
	stringTree.add("times");
	stringTree.add("many");
	stringTree.add("ways");
	stringTree.add("Merry"); // capitalized letters are ordered before lowercase
	stringTree.add("Christmas");

	stringTree.remove("many");
	stringTree.remove("on");
	stringTree.remove("at");
	stringTree.remove("an");

	std::cout << "\nNow there are " << stringTree.countItems() << " nodes in the STRING tree." << std::endl;

	std::cout << "\n";
	stringTree.printAsTree(18); // passing an int arg to print as tree sets the data spacing for the tree display
	std::cout << "\n";

	std::cout << "\n==========================================================" << std::endl;

	//making copies so the original trees are not changed
	BinaryTree<int> intTree_copy(intTree);
	BinaryTree<double> doubleTree_copy(doubleTree);
	BinaryTree<std::string> stringTree_copy(stringTree);

	intTree_copy.inOrderTraverse(doubleMyData);
	doubleTree_copy.inOrderTraverse(doubleMyData);
	stringTree_copy.inOrderTraverse(doubleMyData);

	std::cout << "\nNow all the entries have been doubled!\n"<< std::endl;

	//print the doubled data
	intTree_copy.printAll();
	std::cout << "\n";
	doubleTree_copy.printAll();
	std::cout << "\n";
	stringTree_copy.printAll();
	std::cout << "\n";

	//output the doubled data to a file
	intTree_copy.writeFile("DoubleIntOut.dat");
	doubleTree_copy.writeFile("DoubleDoubleOut.dat");
	stringTree_copy.writeFile("DoubleStringOut.dat");

	std::cout << "\nOutputting data..." << std::endl;

	//clear the copies;
	intTree_copy.clear();
	doubleTree_copy.clear();
	stringTree_copy.clear();

	std::cout << "\nClearing copies...\n" << std::endl;

	std::cout << "Now there are " << intTree_copy.countItems() << " nodes in the INT tree copy." << std::endl;
	std::cout << "Now there are " << doubleTree_copy.countItems() << " nodes in the DOUBLE tree copy." << std::endl;
	std::cout << "Now there are " << stringTree_copy.countItems() << " nodes in the STRING tree copy." << std::endl;

	std::cout << "\nPress any key to continue..." << std::endl;
	std::cin.get();
	return 0;
}

//User defined template function implementation for modifying data in the tree.
template <class Item>
void doubleMyData(Item& data, int number, int depth)
{
	data = data + data;
}
