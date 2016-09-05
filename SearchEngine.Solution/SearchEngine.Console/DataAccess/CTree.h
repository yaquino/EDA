#pragma once
#include "../Core/ITree.h"

template <class T>
class CTree : virtual public ITree<T> {

public:
	CTree();
	~CTree();
	bool Insert(T);
	bool Search(T);
};