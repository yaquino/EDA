#pragma once
#include "../Core/DataTypes.h"
#include "../Core/INode.h"

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
	T GetData();
	bool SetData(T);
		
	T& getKey();
	bool setkey(T);
	int getLength();
	bool setLength(int);
	CNode<T>*& Child();
	CNode<T>*& Brother();

};