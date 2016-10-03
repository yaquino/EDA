#pragma once

#include "DataTypes.h"

class IParser {
public:
	virtual T_BOOL LoadStopWord(FILE_NAME) = 0;
	virtual T_BOOL ParseFile() = 0;
	virtual T_BOOL IsStopWord(T_WORD) = 0;
	virtual T_BOOL IsMark(T_CHAR) = 0;
	virtual T_BOOL NoMark(T_CHAR&) = 0;
	virtual T_BOOL PreProcessWord(T_WORD&) = 0;
};