#pragma once

#include "DataTypes.h"

class IParser {
public:
	virtual bool read(FILE_NAME) = 0;
};

