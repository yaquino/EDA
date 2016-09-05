#pragma once


#include "../Core/DataTypes.h"
#include "../Core/INode.h"

template <class T>
class CNode : virtual public INode {

public:
	CNode();
	~CNode();
	T GetData();
	bool SetData(T);
	INode<T> GetChild(NUMBER_CHILD);
};
