#pragma once
#ifndef INODE_H
#define INODE_H

#include "DataTypes.h"

template <class T>
class INode {
public:
	virtual INode<T>*& Child() = 0;
	virtual INode<T>*& Brother() = 0;
};

#endif