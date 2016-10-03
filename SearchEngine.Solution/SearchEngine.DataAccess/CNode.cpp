#include "CNode.h"

template <class T>
CNode<T>::CNode(): counter(0){}

template <class T>
CNode<T>::~CNode() {}

template <class T>
CNode<T>::CNode(T new_key, int set_lenght) : key(new_key), length(set_lenght), counter(0) {};

template <class T>
T& CNode<T>::GetKey() {
	return key;
}

template <class T>
bool CNode<T>::Setkey(T new_key) {
	key = new_key;
	return true;
}

template <class T>
int CNode<T>::GetLength() {
	return length;
}

template <class T>
unsigned int &CNode<T>::GetCounter() {
	return counter;
}

template <class T>
bool CNode<T>::SetLength(int new_length) {
	length = new_length;
	return true;
}

template <class T>
INode<T>*& CNode<T>::Child() {
	return this->link;
}

template <class T>
INode<T>*& CNode<T>::Brother() {
	return this->next;
}
