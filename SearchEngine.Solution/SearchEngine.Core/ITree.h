#pragma once
#include "DataTypes.h"
#include "INode.h"

template <class T>
class ITree {
public:
	virtual INode<T>* Find(T) = 0;
	virtual T_BOOL Insert(T, int) = 0;
	virtual void Save(string) = 0;
	virtual void Load(string) = 0;
};