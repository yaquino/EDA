#pragma once
#include "../SearchEngine.Core/ITree.h"
#include "CNode.h"

template <class T>
class CTree : virtual public ITree<T> {
private:
	CNode<T>* root;

public:
	CTree();
	~CTree();
	bool Insert(T);
	bool Search(T);

	CNode<T>* getRoot();
	bool setRoot(CNode<T>*);
	bool insertWord(WORD);
	int Prefix(T, T);
	CNode<T>* Find(CNode<T>*, T, int);
	CNode<T>* Find(T);
	void Split(CNode<T>*, int);
	CNode<T>* Insert(CNode<T>*, T, int);
	
};