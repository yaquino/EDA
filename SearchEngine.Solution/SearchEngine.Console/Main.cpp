#include "../SearchEngine.Core/ITree.h"
#include "../SearchEngine.DataAccess/CTree.h"
#include "../SearchEngine.DataAccess/CTree.cpp"

#include "../SearchEngine.Core/ISearchEngine.h"
#include "../SearchEngine.Lib/CSearchEngine.h"
#include <iostream>
using namespace std;

int main() {

	ITree<string> *my_trial = new CTree<string>;
	my_trial->Insert("abab");
	my_trial->Insert("aba");
	my_trial->Insert("bc");
	my_trial->Insert("baca");
	if (my_trial->Find("baca")) {
		cout << "Ya encontre" << endl;
	}

	return 0;
}