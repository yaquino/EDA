#pragma once

#include "DataTypes.h"

class IPage {
public:
	virtual FILE_NAME GetName() = 0;
	virtual NUMBER_LINES GetNumberLines() = 0;
};
