#pragma once

#include "DataTypes.h"
#include "INode.h"
template <class T>
class ITree {
public:
	virtual bool Insert(T) = 0;
	virtual bool Search(T) = 0;
};

