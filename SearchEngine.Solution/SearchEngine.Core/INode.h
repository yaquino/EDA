#pragma once
#include "DataTypes.h"

template <class T>
class INode {
public:
	virtual T& getKey() = 0;
	virtual int getLength() = 0;
	virtual bool setLength(int) = 0;
	virtual INode<T>*& Child() = 0;
	virtual INode<T>*& Brother() = 0;
};
