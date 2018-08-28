#pragma once
#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/INode.h"

template <class T>
class CNode : virtual public INode<T> {

private:
	T key;
	T_INT counter;
	T_INT length;
	INode<T>* link;
	INode<T>* next;

public:
	CNode();
	CNode(T, int, int = 0);
	~CNode();

	T& GetKey();
	T_BOOL Setkey(T);
	T_INT GetLength();
	T_BOOL SetLength(int);
	T_INT& GetCounter();	

	INode<T>*& Child();
	INode<T>*& Brother();

};