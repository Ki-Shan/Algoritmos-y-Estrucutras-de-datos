#include "BST.h"


searchtree::searchtree() {
	root = nullptr;
}

searchtree::~searchtree() {
	deleteTree(root);
	root = nullptr;
}

void searchtree::printTree(treeElement*& p_pStelle, int p_iEbene)
{
	if (p_pStelle == nullptr)
	{
		return;
	}
	else
	{
		printTree(p_pStelle->right, p_iEbene + 1);
		for (int i = 1; i <= p_iEbene; i++)
			cout << "\t";
		cout << p_pStelle->val << endl;		
		printTree(p_pStelle->left, p_iEbene + 1);
	}
}

void searchtree::printTree()
{
	cout << "\nArbol: \n--------------------------------\n\n";
	if (this->root != nullptr)
	{
		printTree(this->root->right, 1);
		cout << this->root->val << endl;
		printTree(this->root->left, 1);
	}
	else
		cout << "\nEl Arbol esta vacio!" << endl;
	cout << "\n--------------------------------\n\n";
}

void searchtree::deleteTree(treeElement * root) {
	if (root != nullptr) {
		if (root->left != nullptr) deleteTree(root->left);
		if (root->right != nullptr) deleteTree(root->right);
		delete root;
	}
}

bool searchtree::contains(object o) {
	treeElement* curr = root;
	while (curr != nullptr) {
		if (curr->val == o) {
			return true;
		}
		else {
			if (o <= curr->val)
				curr = curr->left;
			else
				curr = curr->right;
		}
	}
	return false;
}

void searchtree::delete_val(object o)
{
	searchTarget(root, o);
}

void searchtree::searchTarget(treeElement * &root, object o) {

	if (root == nullptr)
		return;
	// root pasa a ser la raiz del subarbol donde se borrara el elemento
	if (o == root->val) {
		// Elemento a borrar fue encontrado, procedemos a borrar
		searchtree::removeTarget(root, o);
	}
	else {
		// Navegamos por el arbol hasta encontrar el elemento
		if (o > root->val) {
			searchtree::searchTarget(root->right, o);
			return;
		}
		else {
			if (o < root->val) {
				searchtree::searchTarget(root->left, o);
				return;
			}
		}
	}
}

void searchtree::removeTarget(treeElement * &root, object o) {

	// caso 1: Elemento sin hijos (Sin Suc)
	if (root->left == nullptr && root->right == nullptr) {

		// encontrar el padre
		if (root->val >= root->father->val)
		{
			// elemento a la derecha del padre
			auto tmp = root->father;
			delete tmp->right;
			tmp->right = nullptr;
		}
		else {
			if (root->val < root->father->val)
			{
				// elemento a la izquierda del padre
				auto tmp = root->father;
				delete tmp->left;
				tmp->left = nullptr;
			}
		}
		return;
	}
	if (root != nullptr) {
		// caso 2: Elemento con 1 hijo: cambiar valor con el hijo y borrar a este
		if (root->left == nullptr && root->right != nullptr) {
			// hijo esta a la derecha
			root->val = root->right->val;
			searchtree::removeTarget(root->right, root->right->val);
		}
		if (root->left != nullptr && root->right == nullptr) {
			// hijo esta a la izquerda
			root->val = root->left->val;
			searchtree::removeTarget(root->left, root->left->val);
		}
		// caso 3: Elemento tiene 2 hijos
		if (root->left != nullptr && root->right != nullptr) {
			// buscar el sucessor inorder
			auto inOrd = searchtree::search_inorder(root->right);
			// cambiar valores
			root->val = inOrd->val;
			// borrar el inorder
			searchtree::removeTarget(inOrd, inOrd->val);
		}
		return;
	}

}

treeElement*& searchtree::search_inorder(treeElement * &elem)
{
	// El inorder element es el primer elemento a la izquierda del
	// elemento a la derecha del node.
	if (elem->left != nullptr) {
		searchtree::search_inorder(elem->left);
	}
	else {
		return elem;
	}
}

void searchtree::insert(object o) {
	treeElement* elem = new treeElement;
	elem->val = o; elem->left = NULL; 
	elem->right = NULL; elem->father = NULL;
	if (root == NULL)
		root = elem;
	else insert(root, elem);
}

void searchtree::insert(treeElement * currRoot, treeElement * elem) {
	if (elem->val <= currRoot->val) {
		if (currRoot->left == NULL) {
			currRoot->left = elem;
			currRoot->left->father = currRoot;
		}
		else insert(currRoot->left, elem);
	}
	else {
		if (currRoot->right == NULL) {
			currRoot->right = elem;
			currRoot->right->father = currRoot;
		}
		else insert(currRoot->right, elem);
	}
}

void searchtree::print_Inorder() {
	print_Inorder(root); cout << endl;
}

void searchtree::print_Inorder(treeElement * root) {
	if (root != nullptr) {
		cout << "(";
		print_Inorder(root->left); // left
		cout << "," << root->val << ","; // root
		print_Inorder(root->right); // right
		cout << ")";
	}
	else { cout << "n"; }
}

treeElement* searchtree::get_root()
{
	return root;
}

