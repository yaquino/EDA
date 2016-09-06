#pragma once


#include "DataTypes.h"

template <class T>
class INode {
public:
	virtual INode<T>*& Child() = 0;
	virtual INode<T>*& Brother() = 0;
};
