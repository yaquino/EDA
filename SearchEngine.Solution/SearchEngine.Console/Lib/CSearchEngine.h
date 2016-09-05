#pragma once
#ifndef CSEARCHENGINE_H
#define CSEARCHENGINE_H

#include "../Core/DataTypes.h"
#include "../Core/ISearchEngine.h"
#include "../Core/IParser.h"
#include "../Core/IIndexer.h"
#include "../Core/ITree.h"

#include "../Lib/CIndexer.h"
#include "../Lib/CParser.h"
#include "../DataAccess/CTree.h"

class CSearchEngine : virtual public ISearchEngine {

public:
	CSearchEngine();
	~CSearchEngine();
	bool Load(MEMORY, FILE_NAME);
	bool Search(_TOSEARCH_);
};

#endif