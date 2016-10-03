#pragma once
#include "DataTypes.h"

template <class T>
class INode {
public:
	virtual T& GetKey() = 0;
	virtual int GetLength() = 0;
	virtual bool SetLength(int) = 0;
	virtual unsigned int &GetCounter() = 0;
	virtual INode<T>*& Child() = 0;
	virtual INode<T>*& Brother() = 0;
};
