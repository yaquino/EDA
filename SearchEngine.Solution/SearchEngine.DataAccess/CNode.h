#include "../SearchEngine.Core/INode.h"

template <class T>
class Node : public INode<T> {

private:
	T key;
	T_INT counter;
	T_INT length;	
	INode<T>* link;
	INode<T>* next;

public:
	CNode(T, int);
	CNode();
	~CNode();
		
	T& GetKey();
	T_BOOL Setkey(T);
	T_INT GetLength();
	T_INT& GetCounter();
	T_BOOL SetLength(int);
	INode<T>*& Child();
	INode<T>*& Brother();

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