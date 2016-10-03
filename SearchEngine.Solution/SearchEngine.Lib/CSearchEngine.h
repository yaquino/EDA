#pragma once

#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/ISearchEngine.h"
#include "../SearchEngine.Core/IParser.h"
#include "../SearchEngine.Core/ITree.h"

#include "../SearchEngine.Lib/CParser.h"
#include "../SearchEngine.DataAccess/CTree.h"

class CSearchEngine : virtual public ISearchEngine {

public:
	CSearchEngine();
	~CSearchEngine();
	T_BOOL Load(MEMORY, FILE_NAME);
	T_BOOL Search(_TOSEARCH_);
};
