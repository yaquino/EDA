#pragma once

template <class T>
class IGeneric {
public:
	virtual T* getmemory() = 0;
};
