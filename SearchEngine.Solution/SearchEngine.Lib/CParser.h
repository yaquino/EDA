#pragma once

#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/IParser.h"

class CParser : virtual public IParser {

public:
	CParser();
	~CParser();
	bool read(FILE_NAME);
};
