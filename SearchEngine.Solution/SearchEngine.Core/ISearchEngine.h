#pragma once
#ifndef ISEARCHENGINE_H
#define ISEARCHENGINE_H

#include "DataTypes.h"

class ISearchEngine {
public:
	virtual bool Load(MEMORY, FILE_NAME) = 0;
	virtual bool Search(_TOSEARCH_) = 0;
};

#endif