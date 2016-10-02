#include "CSearchEngine.h"

CSearchEngine::CSearchEngine() {
}
CSearchEngine::~CSearchEngine() {
}
bool CSearchEngine::Load(MEMORY _mem, FILE_NAME _file){
	// Crea el arbol y las nubes
	IParser *parser;
	IIndexer *indexer;

	return true;
}
bool CSearchEngine::Search(_TOSEARCH_ _string) {	
	ITree<string> *my_trial = new CTree<string>;
	/*my_trial->Insert("abab");
	my_trial->Insert("bc");
	my_trial->Insert("baca");
	if (my_trial->Find(_string)) {
		return true;
	}*/
	return false;
}
