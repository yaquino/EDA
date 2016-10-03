#pragma once
#include "DataTypes.h"

class ICloud {
public:
	virtual void Insert(int ID, int block)=0;
};