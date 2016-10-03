#include "../SearchEngine.Core/ITree.h"
#include "../SearchEngine.DataAccess/CTree.h"
#include "../SearchEngine.DataAccess/CTree.cpp"

#include "../SearchEngine.Core/IParser.h"
#include "../SearchEngine.Lib/CParser.cpp"
#include "../SearchEngine.Core/ISearchEngine.h"
#include "../SearchEngine.Lib/CSearchEngine.h"

#include <iostream>
#include <ctime>

int main(int argc, char* argv[]) {
	
	ITree<string> *my_trial = new CTree<string>;
	/*my_trial->Insert("abab");
	my_trial->Insert("aba");
	my_trial->Insert("bc");
	my_trial->Insert("baca");
	my_trial->Insert("bac");*/

	ifstream file;
	string line, word;
	int number;
	istringstream iss;

	bool condition = true;

	char option;

	/*while (condition) {

	file.open("words.txt");
	while (!file.eof()) {
	getline(file, line);

	iss.str(line);

	iss >> word;

	iss >> number;

	my_trial->Insert(word, number);

	iss.clear();

	}
	file.close();
	cout << "Opcion: ";
	cin >> option;
	if (option == 'p') {
	my_trial->Save("persistence.txt");
	}
	}*/

	/*file.open("in.txt");
	while (!file.eof()) {
	getline(file, line);

	iss.str(line);

	iss >> word;

	iss >> number;

	my_trial->Insert(word, number);

	iss.clear();

	}
	my_trial->Save("persistence.txt");*/


	clock_t begin = clock();
	my_trial->Load("persistence.txt");
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;

	/*if (my_trial->Find("cumbre")) {
	cout << "Ya encontre" << endl;
	}*/



	cout << "Cute " << elapsed_secs << endl;

	/*if (my_trial->Find("baca")) {
	cout << "Ya encontre" << endl;
	}*/

	return 0;
}