#include "../SearchEngine.Core/ITree.h"
#include "../SearchEngine.DataAccess/CTree.h"
#include "../SearchEngine.DataAccess/CTree.cpp"

#include "../SearchEngine.Core/IParser.h"
#include "../SearchEngine.Lib/CParser.cpp"
#include "../SearchEngine.Core/ISearchEngine.h"
#include "../SearchEngine.Lib/CSearchEngine.h"


int main(int argc, char* argv[]) {
	IParser *parser = new CParser();
	parser->LoadStopWord("stopwords.txt");

	ITree<string> *my_tree = new CTree<string>;
	// load tree

	map<string, int> palabras_de_busqueda;
	for (int i = 1; i < argc; i++) {
		if (parser->IsStopWord(argv[i]) == false) {
			INode<string>* find = my_tree->Find(argv[i]);
			palabras_de_busqueda.insert(pair<string, int>(argv[i], find->GetCounter()));
		}
	}


	return 0;
}