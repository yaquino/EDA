#pragma once
#include "../SearchEngine.Core/ITree.h"
#include "CNode.h"
#include "CNode.cpp"

template <class T>
class CTree : virtual public ITree<T> {
private:
	INode<T>* root;

public:
	CTree();
	~CTree();

	INode<T>* GetRoot();
	bool SetRoot(INode<T>*);
	bool InsertWord(WORD);
	int Prefix(T, T);
	INode<T>* Find(T);
	INode<T>* Find(INode<T>*, T);
	void Split(INode<T>*, int);
	bool Insert(T);
	INode<T>* Insert(INode<T>*, T);
	
};