#include "../SearchEngine.Core/ITree.h"
#include "../SearchEngine.DataAccess/CTree.h"
#include "../SearchEngine.DataAccess/CTree.cpp"

#include "../SearchEngine.Core/ISearchEngine.h"
#include "../SearchEngine.Lib/CSearchEngine.h"
#include <iostream>
using namespace std;

int main() {
	ITree<string> *my_trial = new CTree<string>;

	return 0;
}