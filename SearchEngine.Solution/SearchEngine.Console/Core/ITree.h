#pragma once
#ifndef ITREE_H
#define ITREE_H

#include "DataTypes.h"
template <class T>
class ITree {
public:
	virtual bool Insert(T) = 0;
	virtual bool Search(T) = 0;
};

#endif