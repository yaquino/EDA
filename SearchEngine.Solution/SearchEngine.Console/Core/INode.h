#pragma once
#ifndef INODE_H
#define INODE_H

#include "DataTypes.h"

template <class T>
class INode{ 
public:
	virtual T GetData() = 0;
	virtual bool SetData(T) = 0;	
};

#endif