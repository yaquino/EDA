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
T_INT CTree<T>::Prefix(T key_a, T key_b) { // length of the biggest common prefix of x and key strings
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
	unsigned int k = Prefix(key, node->GetKey());
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
void CTree<T>::Split(INode<T>* node, T_INT k) { // dividing node according to k key symbol
	INode<T>* p = new CNode<T>(node->GetKey().substr(k, node->GetLength()), node->GetLength() - k, node->GetCounter());
	p->Child() = node->Child();
	node->Child() = p;
	node->GetKey().erase(k, node->GetLength());
	node->SetLength(k);
	node->GetCounter() = 0;
}

template <class T>
bool CTree<T>::Insert(T key, int number) {
	INode<T>* p = Insert(root, key, number);

	if (!root) {
		root = p;
	}

	return true;
}

template <class T>
INode<T>* CTree<T>::Insert(INode<T>* node, T key, int number) { // inserting key in tree
	if (!node) {
		return new CNode<T>(key, key.length(), number);
	}
	unsigned int k = Prefix(key, node->GetKey());
	if (k == 0) {
		node->Brother() = Insert(node->Brother(), key, number);
		return node;
	} if (k < node->GetLength()) { // cut or not to cut?
		Split(node, k);
		if (k < key.length()) {
			node->Child() = Insert(node->Child(), key.substr(k, key.length()), number);
		}
		return node;
	} if (k < key.length()) {
		node->Child() = Insert(node->Child(), key.substr(k, key.length()), number);
	}
	else {
		node->GetCounter() += number;
	}
	return node;
}


template <class T>
void CTree<T>::TraversalSave(INode<T> *node, ofstream &out) {
	if (!node) {
		out << ";";
	}
	else {
		out << node->GetKey() << '/' << node->GetCounter();
		if (node->Child()) {
			out << ",";
		}
		TraversalSave(node->Child(), out);
		TraversalSave(node->Brother(), out);
	}
}

template <class T>
void CTree<T>::Save(string directory) {
	ofstream file;

	file.open(directory);

	TraversalSave(root, file);

	file.close();
}

template <class T>
void CTree<T>::TraversalLoad(INode<T> *&node, ifstream &file, istringstream &iss) {

	string content, data, key;
	int number;

	istringstream issdata;

	if (iss.rdbuf()->in_avail()) {

		getline(iss, data, ',');

		issdata.str(data);

		getline(issdata, key, '/');

		issdata >> number;

		issdata.clear();

		node = new CNode<T>(key, key.length(), number);

		TraversalLoad(node->Child(), file, iss);

		if (!file.eof()) {

			getline(file, content, ';');
			iss.str(content);

			TraversalLoad(node->Brother(), file, iss);
			iss.clear();
		}
	}
	iss.clear();
}

template <class T>
void CTree<T>::Load(string directory) {

	ifstream file;
	istringstream iss;
	string content;

	INode<T> *&node = root;
	file.open(directory);

	getline(file, content, ';');
	iss.str(content);

	TraversalLoad(node, file, iss);

	file.close();

}