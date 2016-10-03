#pragma once
#include "DataTypes.h"

template <class T>
class INode {
public:
	virtual T& GetKey() = 0;
	virtual T_INT GetLength() = 0;
	virtual T_BOOL SetLength(int) = 0;
	virtual T_INT &GetCounter() = 0;
	virtual INode<T>*& Child() = 0;
	virtual INode<T>*& Brother() = 0;
};
