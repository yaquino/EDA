#pragma once
#ifndef CPARSER_H
#define CPARSER_H

#include "../Core/DataTypes.h"
#include "../Core/IParser.h"

class CParser : virtual public IParser {

public:
	CParser();
	~CParser();
	bool read(FILE_NAME);
};

#endif