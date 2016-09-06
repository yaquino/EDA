#include "CNode.h"
template <class T>
CNode<T>::CNode() {}

template <class T>
CNode<T>::~CNode() {}

template <class T>
T CNode<T>::GetData() {
	return this->key;
}
template <class T>
bool CNode<T>::SetData(T data) {
	this->key = data;
	return true;
}




template <class T>
CNode<T>::CNode(T new_key, int set_lenght) : key(new_key), length(set_lenght) {};

template <class T>
T& CNode<T>::getKey() {
	return key;
}

template <class T>
bool CNode<T>::setkey(T new_key) {
	key = new_key;
	return true;
}

template <class T>
int CNode<T>::getLength() {
	return length;
}

template <class T>
bool CNode<T>::setLength(int new_length) {
	length = new_length;
	return true;
}

template <class T>
CNode<T>*& CNode<T>::Child() {
	return this->link;
}

template <class T>
CNode<T>*& CNode<T>::Brother() {
	return this->next;
}