#pragma once

#include "DataTypes.h"

class IIndexer {
public:
	virtual bool Insert(FILE_NAME, ID_PAGE, POSITION) = 0;
};
