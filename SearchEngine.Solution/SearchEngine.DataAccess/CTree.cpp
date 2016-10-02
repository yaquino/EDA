
#include "CTree.h"
template <class T>
CTree<T>::CTree() {
	this->root = NULL;
}

template <class T>
CTree<T>::~CTree() {
}

template <class T>
bool CTree<T>::Insert(T key) {

	CNode<T>* p = Insert(root, key);

	if (!root) {
		root = p;
	}

	return true;
}

template <class T>
bool CTree<T>::Search(T key) {
	if (Find(root, key))
		return true;
	return false;
}

template <class T>
CNode<T>* CTree<T>::getRoot() {
	return root;
}
template <class T>
bool CTree<T>::setRoot(CNode<T>* new_root) {
	/* Aca faltaa try catch o algooo */
	root = new_root;
	return true;
}
template <class T>
bool CTree<T>::insertWord(WORD new_word) {
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
CNode<T>* CTree<T>::Find(CNode<T>* node, T key, int n = 0) {
	if (!n) {
		n = key.length();
	} if (!node) {
		return 0;
	}
	int k = Prefix(key, node->getKey());
	if (k == 0) {
		return Find(node->Brother(), key, n); // let’s look for the child’s node
	} if (k == n) {
		return node;
	}
	if (k == node->getLength()) {
		return Find(node->Child(), key.substr(k, key.length()), n - k); // let’s look for at the child’s node
	}
	return 0;
}
template <class T>
CNode<T>* CTree<T>::Find(T key) {
	return Find(root, key);
}
template <class T>
void CTree<T>::Split(CNode<T>* node, int k) { // dividing node according to k key symbol

	CNode<T>* p = new CNode<T>(node->getKey().substr(k, node->getLength()), node->getLength() - k);
	p->Child() = node->Child();
	node->Child() = p;
	node->getKey().erase(k, node->getLength());
	node->setLength(k);
}
template <class T>
CNode<T>* CTree<T>::Insert(CNode<T>* node, T key, int n = 0) { // inserting key in tree

	if (!n) {
		n = key.length();
	} if (!node) {
		return new CNode<T>(key, n);
	}
	int k = Prefix(key, node->getKey());
	if (k == 0) {
		node->Brother() = Insert(node->Brother(), key, n);
	}
	else if (k < n) {
		if (k < node->getLength()) { // cut or not to cut?
			Split(node, k);
		}
		node->Child() = Insert(node->Child(), key.substr(k, key.length()), n - k);
	}
	return node;
}

