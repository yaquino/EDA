#pragma once
#ifndef CSEARCHENGINE_H
#define CSEARCHENGINE_H

#include "../Core/DataTypes.h"
#include "../Core/ISearchEngine.h"

class CSearchEngine : ISearchEngine {
public:
	bool Load(MEMORY, FILE_NAME);
	bool Search(_TOSEARCH_);
};

#endif