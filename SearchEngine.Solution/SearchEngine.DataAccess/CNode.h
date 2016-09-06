#pragma once
#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/INode.h"

template <class T>
class CNode : virtual public INode<T> {
private:
	T key;
	int length;
	CNode<T>* link;
	CNode<T>* next;

public:
	CNode(T, int);
	CNode();
	~CNode();
		
	T& getKey();
	bool setkey(T);
	int getLength();
	bool setLength(int);
	INode<T>*& Child();
	INode<T>*& Brother();

};