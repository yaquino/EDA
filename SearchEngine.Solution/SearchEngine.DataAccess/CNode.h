#pragma once
#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/INode.h"

template <class T>
class CNode : virtual public INode<T> {
private:
	T key;
	unsigned int counter;
	int length;	
	INode<T>* link;
	INode<T>* next;

public:
	CNode(T, int);
	CNode();
	~CNode();
		
	T& GetKey();
	bool Setkey(T);
	int GetLength();
	unsigned int& GetCounter();
	bool SetLength(int);
	INode<T>*& Child();
	INode<T>*& Brother();

};