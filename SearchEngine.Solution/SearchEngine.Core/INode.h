#pragma once
#ifndef INODE_H
#define INODE_H

#include "DataTypes.h"
#include "IGeneric.h"

template <class T>
class INode: IGeneric {
public:
	virtual T GetData() = 0;
	virtual bool SetData(T) = 0;
	virtual INode<T> GetChild(NUMBER_CHILD) = 0;
};

#endif