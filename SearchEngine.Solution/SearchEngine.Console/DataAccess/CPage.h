#pragma once


#include "../Core/DataTypes.h"
#include "../Core/IPage.h"

class CPage : virtual public IPage {

public:
	CPage();
	~CPage();
	FILE_NAME GetName();
	NUMBER_LINES GetNumberLines();
};

