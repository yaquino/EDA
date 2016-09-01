#pragma once
#ifndef IGENERIC_H
#define IGENERIC_H

template <class T>
class IGeneric {
public:
	virtual T* getmemory() = 0;
};

#endif