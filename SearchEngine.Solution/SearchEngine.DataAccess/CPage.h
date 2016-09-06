#pragma once


#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/IPage.h"

class CPage : virtual public IPage {
public:
	CPage();
	~CPage();
	FILE_NAME GetName();
	NUMBER_LINES GetNumberLines();
};

