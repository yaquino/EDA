#pragma once

#include "../Core/DataTypes.h"
#include "../Core/IParser.h"

class CParser : virtual public IParser {

public:
	CParser();
	~CParser();
	bool read(FILE_NAME);
};
