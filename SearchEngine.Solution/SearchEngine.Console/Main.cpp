

#include <iostream>
#include <string>
#include "CTree.h"
using namespace std;

int main(){

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