#include "CNode.h"

template <class T>
CNode<T>::CNode() : counter(0) {}

template <class T>
CNode<T>::CNode(T new_key, int set_lenght, int set_counter = 0) : key(new_key), length(set_lenght), counter(set_counter) {};

template <class T>
CNode<T>::~CNode() {}

template <class T>
T& CNode<T>::GetKey() {
	return key;
}

template <class T>
T_BOOL CNode<T>::Setkey(T new_key) {
	key = new_key;
	return true;
}

template <class T>
T_INT CNode<T>::GetLength() {
	return length;
}

template <class T>
T_BOOL CNode<T>::SetLength(int new_length) {
	length = new_length;
	return true;
}

template <class T>
T_INT &CNode<T>::GetCounter() {
	return counter;
}

template <class T>
INode<T>*& CNode<T>::Child() {
	return this->link;
}

template <class T>
INode<T>*& CNode<T>::Brother() {
	return this->next;
}