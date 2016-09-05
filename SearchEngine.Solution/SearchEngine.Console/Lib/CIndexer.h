#pragma once
#include "../Core/DataTypes.h"
#include "../Core/IIndexer.h"

class CIndexer : virtual public IIndexer {

public:
	CIndexer();
	~CIndexer();
	bool Insert(FILE_NAME, ID_PAGE, POSITION);
};

