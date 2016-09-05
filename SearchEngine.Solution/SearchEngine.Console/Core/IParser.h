#pragma once
#ifndef IPARSER_H
#define IPARSER_H

#include "DataTypes.h"

class IParser {
public:
	virtual bool read(FILE_NAME) = 0;
};

#endif