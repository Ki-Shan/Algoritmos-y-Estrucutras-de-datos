#pragma once
#include <iostream>
using namespace std;

typedef int object;
class treeElement {
public:
	object val;			// Valor del Node/Arista
	treeElement* left;	// sucesor a la izquierda
	treeElement* right; // sucesor a la derecha
	treeElement* father; // padre
};

class searchtree {
private:
	treeElement* root;	// Raiz del arbol
	void insert(treeElement* currRoot, treeElement* elem);
	void deleteTree(treeElement* root);
	void print_Inorder(treeElement* root);
	void searchTarget(treeElement*& root, object o);
	void removeTarget(treeElement*& root, object o);
	void printTree(treeElement*& p_pStelle, int p_iEbene);

public:
	searchtree();
	~searchtree();
	void insert(object o);		// Insertar nuevo elemento
	bool contains(object o);
	void delete_val(object o);	// Borrar elemento
	treeElement*& search_inorder(treeElement*& elem);
	treeElement* get_root();	// Raiz

	void print_Inorder();		// Imprimir arbol inorder
	void printTree();			// Imprimir arbol

};

