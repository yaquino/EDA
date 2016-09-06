#pragma once

#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/ISearchEngine.h"
#include "../SearchEngine.Core/IParser.h"
#include "../SearchEngine.Core/IIndexer.h"
#include "../SearchEngine.Core/ITree.h"

#include "../SearchEngine.Lib/CIndexer.h"
#include "../SearchEngine.Lib/CParser.h"
#include "../SearchEngine.DataAccess/CTree.h"

class CSearchEngine : virtual public ISearchEngine {

public:
	CSearchEngine();
	~CSearchEngine();
	bool Load(MEMORY, FILE_NAME);
	bool Search(_TOSEARCH_);
};
