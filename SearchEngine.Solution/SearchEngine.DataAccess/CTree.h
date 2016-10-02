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

	INode<T>* getRoot();
	bool setRoot(INode<T>*);
	bool insertWord(WORD);
	int Prefix(T, T);
	INode<T>* Find(T);
	INode<T>* Find(INode<T>*, T, int = 0);
	void Split(INode<T>*, int);
	bool Insert(T);
	INode<T>* Insert(INode<T>*, T, int = 0);
	
};