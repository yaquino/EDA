

#include "../SearchEngine.Core/ITree.h"
#include "../SearchEngine.DataAccess/CTree.h"

#include "../SearchEngine.Core/ISearchEngine.h"
#include "../SearchEngine.Lib/CSearchEngine.h"
#include <iostream>
#include <string>
#include "CTree.h"
using namespace std;

int main(){	
	ITree<string> *my_trial = new CTree<string>;
	my_trial->Insert("abab");
	my_trial->Insert("bc");
	my_trial->Insert("baca");
	if (my_trial->Search("bac")) {
		cout << "Ya encontre" << endl;
	}

	/*		
	ISearchEngine *search = new CSearchEngine();	
	bool test = search->Search("bac");
	cout << test << endl;
	*/

	printf("hello world");

	Tree<string> my_trial;

	my_trial.Insert("abab");

	my_trial.Insert("bc");

	my_trial.Insert("baca");

	if (my_trial.Find("bac")) {
		cout << "Ya encontre" << endl;
	}

	return 0;
}