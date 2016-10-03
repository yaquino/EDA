#include "CTree.h"

template <class T>
CTree<T>::CTree() {
	this->root = NULL;
}

template <class T>
CTree<T>::~CTree() {
}

template <class T>
INode<T>* CTree<T>::GetRoot() {
	return root;
}

template <class T>
T_BOOL CTree<T>::SetRoot(INode<T>* new_root) {
	/* Aca faltaa try catch o algooo */
	root = new_root;
	return true;
}

template <class T>
T_BOOL CTree<T>::InsertWord(WORD new_word) {
	return true;
}

template <class T>
int CTree<T>::Prefix(T key_a, T key_b) { // length of the biggest common prefix of x and key strings
	for (unsigned int i = 0; i < key_a.length(); ++i) {
		if (i == key_b.length() || key_a[i] != key_b[i]) {
			return i;
		}
	}
	return key_a.length();
}

template <class T>
INode<T>* CTree<T>::Find(T key) {
	return Find(root, key);
}

template <class T>
INode<T>* CTree<T>::Find(INode<T>* node, T key) {
	if (!node) {
		return 0;
	}
	int k = Prefix(key, node->GetKey());
	if (k == 0) {
		return Find(node->Brother(), key); // let’s look for the child’s node
	} if (k < node->GetLength()) {
		return 0;
	} if (k == key.length()) {
		return node;
	}
	return Find(node->Child(), key.substr(k, key.length()));
}


template <class T>
void CTree<T>::Split(INode<T>* node, int k) { // dividing node according to k key symbol

	INode<T>* p = new CNode<T>(node->GetKey().substr(k, node->GetLength()), node->GetLength() - k);
	p->Child() = node->Child();
	node->Child() = p;
	node->GetKey().erase(k, node->GetLength());
	node->SetLength(k);
}

template <class T>
T_BOOL CTree<T>::Insert(T key) {
	INode<T>* p = Insert(root, key);

	if (!root) {
	root = p;
	}

	return true;
}

template <class T>
INode<T>* CTree<T>::Insert(INode<T>* node, T key) { // inserting key in tree
	if (!node) {
		return new CNode<T>(key, key.length());
	}
	int k = Prefix(key, node->GetKey());
	if (k == 0) {
		return node->Brother() = Insert(node->Brother(), key);
	} if (k < node->GetLength()) { // cut or not to cut?
		Split(node, k);
		if (k < key.length()) {
			node->Child() = Insert(node->Child(), key.substr(k, key.length()));
		}
		return node;
	} if (k < key.length()) {
		node->Child() = Insert(node->Child(), key.substr(k, key.length()));
	} else {
		++node->GetCounter();
	} 
	return node;
}

