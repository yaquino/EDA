#include "../SearchEngine.Core/ITree.h"
#include "../SearchEngine.DataAccess/CTree.h"
#include "../SearchEngine.DataAccess/CTree.cpp"

#include "../SearchEngine.Core/IParser.h"
#include "../SearchEngine.Lib/CParser.cpp"
#include "../SearchEngine.Core/ISearchEngine.h"
#include "../SearchEngine.Lib/CSearchEngine.h"

double getMilisegundos(clock_t c)
{
	double tiempo = 0;
	tiempo = ((c / (double)CLOCKS_PER_SEC) * 1000);
	return tiempo;
}

int main(int argc, char* argv[]) {
	IParser *parser = new CParser();
	parser->LoadStopWord("stopwords.txt");

	ITree<string> *my_trial = new CTree<string>;
	
	ifstream file;
	string line, word;
	int number;
	istringstream iss;
	bool condition = true;
	char option;
	clock_t begin = clock();
	my_trial->Load("persistence.txt");
	clock_t end = clock();
	double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
	cout << "Time " << elapsed_secs << endl;



	// load tree
	argc = 6;
	argv[1] = "casa";
	argv[2] = "de";
	argv[3] = "familia";
	argv[4] = "la";
	argv[5] = "perro";
	//map<string, int> palabras_de_busqueda;
	vector<string> palabras(0);
	for (int i = 1; i < argc; i++) {
		if (parser->IsStopWord(argv[i]) == false) {
			//INode<string>* find = my_tree->Find(argv[i]);
			//palabras_de_busqueda.insert(pair<string, int>(argv[i], find->GetCounter()));
			//if (my_tree->Find(argv[i])) 
				palabras.push_back(argv[i]);
		}
	}

	ISearchEngine *search = new CSearchEngine();
	string archivo_respuesta = "SEARCH_RESULT.txt";
	string archivo_temporal =  "ARC_TEMP.txt";
	bool fl = true;
	if (palabras.size() >= 2) {
		for (int i = 1; i < palabras.size(); i++) {
			if (i == 1) {
				string F1 = palabras[i - 1] + ".txt";
				string F2 = palabras[i] + ".txt";
				search->funcion_Matching(F1, F2, archivo_respuesta);
			}
			else {
				if (i % 2 == 0){
					string F2 = palabras[i] + ".txt";
					search->funcion_Matching(F2, archivo_respuesta, archivo_temporal);
					fl = false;
				}
				else {
					string F2 = palabras[i] + ".txt";
					search->funcion_Matching(F2, archivo_temporal, archivo_respuesta);
					fl = true;
				}
			}
		}
	}
	else {
		string F1 = palabras[0] + ".txt";
		search->funcion_Copy(F1, archivo_respuesta);		
	}
	clock_t h_tIni, h_tFin;
	h_tIni = clock();
	char name_file[1000];
	if (fl) 
		strcpy_s(name_file, archivo_respuesta.c_str());	
	else 
		strcpy_s(name_file, archivo_temporal.c_str());	
	search->BuscarURLs(name_file, "url_table.txt", "urlsalida.txt", "urlindex.txt");
	h_tFin = clock();
	cout << "tiempo utilizado: " << getMilisegundos(h_tFin - h_tIni) << " milisegundos" << endl;



	return 0;
}