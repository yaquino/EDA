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
	T_BOOL SetRoot(INode<T>*);
	T_BOOL InsertWord(WORD);
	T_INT Prefix(T, T);
	INode<T>* Find(T);
	INode<T>* Find(INode<T>*, T);
	void Split(INode<T>*, T_INT);
	T_BOOL Insert(T, int);
	INode<T>* Insert(INode<T>*, T, int);
	void TraversalSave(INode<T>*, ofstream&);
	void Save(string);
	void TraversalLoad(INode<T>*&, ifstream&, istringstream&);
	void Load(string);
};
