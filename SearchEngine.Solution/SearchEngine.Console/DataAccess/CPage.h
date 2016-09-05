#pragma once
#ifndef CPAGE_H
#define CPAGE_H

#include "../Core/DataTypes.h"
#include "../Core/IPage.h"

class CPage : virtual public IPage {

public:
	CPage();
	~CPage();
	FILE_NAME GetName();
	NUMBER_LINES GetNumberLines();
};

#endif