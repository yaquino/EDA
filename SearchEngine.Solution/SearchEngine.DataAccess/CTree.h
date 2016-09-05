#include "../SearchEngine.Core/ITree.h"
#include "CNode.h"

template <class T>
class Tree : public ITree<T> {

private:
	Node<T>* root;

public:

	Tree() : root(NULL) {};
	/*
	Set & get
	*/
	Node<T>* getRoot() {
		return root;
	}
	bool setRoot(Node<T>* new_root) {
		/* Aca faltaa try catch o algooo*/
		root = new_root;
		return true;
	}
	bool insertWord(WORD new_word) {
		return true;
	}

	int Prefix(T key_a, T key_b) { // length of the biggest common prefix of x and key strings
		for (unsigned int i = 0; i < key_a.length(); ++i) {
			if (i == key_b.length() || key_a[i] != key_b[i]) {
				return i;
			}
		}
		return key_a.length();
	}

	Node<T>* Find(Node<T>* node, T key, int n = 0) {
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

	Node<T>* Find(T key) {
		return Find(root, key);
	}

	void Split(Node<T>* node, int k) { // dividing node according to k key symbol

		Node<T>* p = new Node<T>(node->getKey().substr(k, node->getLength()), node->getLength() - k);
		p->Child() = node->Child();
		node->Child() = p;
		node->getKey().erase(k, node->getLength());
		node->setLength(k);
	}

	Node<T>* Insert(Node<T>* node, T key, int n = 0) { // inserting key in tree

		if (!n) {
			n = key.length();
		} if (!node) {
			return new Node<T>(key, n);
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

	bool Insert(T key) {

		Node<T>* p = Insert(root, key);

		if (!root) {
			root = p;
		}

		return true;
	}
};