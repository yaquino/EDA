#pragma once
#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/IIndexer.h"

class CIndexer : virtual public IIndexer {

public:
	CIndexer();
	~CIndexer();
	bool Insert(FILE_NAME, ID_PAGE, POSITION);
};

