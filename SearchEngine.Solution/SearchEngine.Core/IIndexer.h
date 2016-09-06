#pragma once
#ifndef IINDEXER_H
#define IINDEXER_H

#include "DataTypes.h"

class IIndexer {
public:
	virtual bool Insert(FILE_NAME, ID_PAGE, POSITION) = 0;
};

#endif