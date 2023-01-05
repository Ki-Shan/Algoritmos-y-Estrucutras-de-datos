#include "BST.h"

int main() {

	searchtree A;
	A.insert(4);
	A.insert(7);
	A.insert(10);
	A.insert(3);
	A.insert(8);
	A.insert(2);
	A.insert(12);
	A.insert(6);
	A.insert(5);
	A.insert(11);
	A.insert(13);
	A.printTree();
	A.print_Inorder();

	std::cout << "\nBorrando elemento: " << 10;
	A.delete_val(10);
	A.printTree();

	std::cout << "\nBorrando elemento: " << 7;
	A.delete_val(7);
	A.printTree();

	std::cout << "\nBorrando elemento: " << 2;
	A.delete_val(2);
	A.printTree();

	std::cout << "\nBorrando elemento: " << 8;
	A.delete_val(8);
	A.printTree();

	std::cout << "\nBorrando elemento: " << 5;
	A.delete_val(5);
	A.printTree();

	std::cout << "\nBorrando elemento: " << 13;
	A.delete_val(13);
	A.printTree();

	std::cout << "\nBorrando elemento: " << 4;
	A.delete_val(4);
	A.printTree();

	return 0;
}