#pragma once
#ifndef IPAGE_H
#define IPAGE_H

#include "DataTypes.h"

class IPage {
public:
	virtual FILE_NAME GetName() = 0;
	virtual NUMBER_LINES GetNumberLines() = 0;
};

#endif