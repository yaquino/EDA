#pragma once

#include "DataTypes.h"

class ISearchEngine {
public:
	virtual T_BOOL Load(MEMORY, FILE_NAME) = 0;
	virtual T_BOOL Search(_TOSEARCH_) = 0;
};
