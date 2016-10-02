#pragma once

#include "DataTypes.h"
#include "INode.h"
template <class T>
class ITree {
public:

	virtual INode<T>* Find(T) = 0;
	virtual bool Insert(T) = 0;
};
