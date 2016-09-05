#include "../SearchEngine.Core/INode.h"

template <class T>
class Node : public INode<T> {

private:
	T key;
	int length;
	Node<T>* link;
	Node<T>* next;

public:

	Node(T new_key, int set_lenght) : key(new_key), length(set_lenght) {};

	T& getKey() {
		return key;
	}

	bool setkey(T new_key) {
		key = new_key;
		return true;
	}

	int getLength() {
		return length;
	}

	bool setLength(int new_length) {
		length = new_length;
		return true;
	}

	Node<T>*& Child() {
		return this->link;
	}

	Node<T>*& Brother() {
		return this->next;
	}
};