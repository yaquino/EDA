#include "CSearchEngine.h"

CSearchEngine::CSearchEngine() {
}
CSearchEngine::~CSearchEngine() {
}
void CSearchEngine::Cuenta(T_STRING s, T_CCHAR Separadorr, T_INT & TotalChars) {
	for (int i = 0; i < s.size(); i++)
		if (s[i] == Separadorr) { TotalChars++; break; }
}
void CSearchEngine::split(T_STRING Linea, T_CHAR Separador, V_STRING &TempBuff, T_INT &TotalVector) {
	TempBuff.resize(0);
	TotalVector = 0;
	int Nums = -1;
	int NumPos = -1;
	int ValorNum = 0;
	T_INT TotalChars = 0;
	int TotalEspacios = Linea.length();
	string Valor;
	Cuenta(Linea, Separador, TotalChars);
	if (TotalChars != 0) {
		while (Nums < TotalChars) {
			Nums++;
			ValorNum = Linea.find(Separador, NumPos + 1);
			Valor = Linea.substr(NumPos + 1, ValorNum);
			Valor = Valor.substr(0, Valor.find_first_of(Separador));
			TempBuff.push_back(Valor);
			NumPos = ValorNum;
			TotalEspacios++;
		}
		TotalVector = TempBuff.size();
	}
	else {
		TotalVector = 0;
	}
}

T_INT CSearchEngine::compare(T_CHAR* a, T_CHAR* b) {
	if (strlen(a) > strlen(b))
		return 1;
	else {
		if (strlen(a) < strlen(b))
			return -1;
		else {
			return strcmp(a, b);
		}
	}
}
T_INT CSearchEngine::funcion_Matching(FILE_NAME s1, FILE_NAME s2, FILE_NAME sr) {
	fflush(stdin);
	string line1, line2;
	const char* Ruta1 = s1.c_str();
	const char* Ruta2 = s2.c_str();
	const char* respuesta = sr.c_str();
	ifstream File1(Ruta1, ios::in);
	ifstream File2(Ruta2, ios::in);
	if (File1.fail() || File2.fail()) {
		return 0; // error al abrir documento
	}
	if (!File1.eof() && !File2.eof()) {
		ofstream resultado(sr, ios::out);
		getline(File1, line1);
		getline(File2, line2);
		while (!File1.eof() && !File2.eof()) {
			vector<string> Temp_File1(0);
			vector<string> Temp_File2(0);
			T_INT TotalVector;
			split(line1, *" ", Temp_File1, TotalVector);
			const char* id_doc1 = Temp_File1[0].c_str();
			char id1[100];
			strcpy_s(id1, id_doc1);
			split(line2, *" ", Temp_File2, TotalVector);
			const char* id_doc2 = Temp_File2[0].c_str();
			char id2[100];
			strcpy_s(id2, id_doc2);
			int rpta = compare(id1, id2);
			fflush(stdin);
			if (rpta == 0) {
				resultado << flush << id1 << endl << flush;
				getline(File2, line2);
			}
			else {
				if (rpta < 0)
					getline(File1, line1);
				else
					getline(File2, line2);
			}
		}
		resultado.close();
		return 2;
	}
	else {
		return 1; // Algun fichero vacio
	}
}

T_INT CSearchEngine::funcion_Copy(FILE_NAME s1, FILE_NAME sr) {
	fflush(stdin);
	string line1;
	const char* Ruta1 = s1.c_str();
	const char* respuesta = sr.c_str();
	ifstream File1(Ruta1, ios::in);
	if (File1.fail()) {
		return 0; // error al abrir documento
	}
	if (!File1.eof()) {
		ofstream resultado(sr, ios::out);
		getline(File1, line1);
		while (!File1.eof()) {
			vector<string> Temp_File1(0);
			T_INT TotalVector;
			split(line1, *" ", Temp_File1, TotalVector);
			const char* id_doc1 = Temp_File1[0].c_str();
			char id1[100];
			strcpy_s(id1, id_doc1);
			fflush(stdin);
			resultado << flush << id1 << endl << flush;
			getline(File1, line1);
		}
		resultado.close();
		return 2;
	}
	else {
		return 1; // Algun fichero vacio
	}
}

/**********************************************
* FUNCION PARA OBTENER EL TAMANHO DEL ARCHIVO
**********************************************/
// Para determinar la el tamaño de un archivo
TIPOTAM CSearchEngine::filesize(T_CHAR archivo[])
{
	ifstream stream(archivo, ios::binary);
	if (stream.fail())
		cerr << "Error al abrir el archivo: " << archivo << endl;
	else
	{
		stream.seekg(0, stream.end);

		TIPOTAM length = (TIPOTAM)stream.tellg().seekpos();
		stream.seekg(0, stream.beg);
		stream.close();
		return length;
	}
	return -1;
}

// Genera un indice a partir del archivo de las URLs
T_INT CSearchEngine::IndexarURLs(T_CHAR *FileOrigen, T_CHAR *FileDestino)
{
	char *bloque, *bloqueOrigen;
	bloque = new char[33];
	bloqueOrigen = new char[BLOQUELINEA];

	ifstream fOrigen(FileOrigen);
	if (fOrigen.fail()) {
		cerr << "Error al abrir el archivo: " << FileOrigen << endl; return 0;
	}
	else
	{
		TIPOTAM i = 0, k = 1, j = 0, l = 0, IDDoc, desde, hasta;
		char numero[33];
		char ch;
		Indice ind;
		ofstream fDestino(FileDestino, ios::binary);
		if (fDestino.fail()) {
			cerr << "Error al abrir el archivo: " << FileDestino << endl; return 0;
		}
		ind.desde = 0;
		while (!fOrigen.eof())
		{
			fDestino.write((char *)(&ind), sizeof(Indice));
			fOrigen.getline(bloqueOrigen, 32000, '\t');
			ind.desde = ind.desde + strlen(bloqueOrigen) + 1;
		}
		fOrigen.close();
		fDestino.close();
	}
	return 0;
}

//Hace la busqueda de de Documentos dentro del listado de URLs
T_INT CSearchEngine::BuscarURLs(T_CHAR *FileIDs, T_CHAR *FileOrigen, T_CHAR *FileDestino, T_CHAR *FileIndexOrigen)
{
	char *bloque, *bloqueOrigen;
	bloque = new char[33];
	bloqueOrigen = new char[BLOQUELINEA];
	ifstream fIDs(FileIDs);
	if (fIDs.fail())
		cerr << "Error al abrir el archivo: " << FileIDs << endl;
	else
	{
		TIPOTAM i = 0, k = 1, j = 0, l = 0, IDDoc;
		char numero[33];
		char ch;

		// el archivo con el indice de las urls
		ifstream fIndexOrigen(FileIndexOrigen, ios::binary);
		if (fIndexOrigen.fail()) {
			cerr << "Error al abrir el archivo: " << FileIndexOrigen << endl; return 0;
		}
		TIPOTAM tamArchivo;
		tamArchivo = filesize(FileIndexOrigen);
		tamArchivo = tamArchivo / sizeof(Indice);
		cout << tamArchivo << endl;

		// Indice en memoria
		Indice *ind;
		ind = new Indice[tamArchivo];
		i = 0;
		ind[i++].desde = 0;
		while (!fIndexOrigen.eof())
		{
			fIndexOrigen.read((char *)(&ind[i++]), sizeof(Indice));
		}
		fIndexOrigen.close();

		/*cout <<"desde"<<ind[0].desde<<endl;
		cout << "desde" << ind[1].desde << endl;
		cout << "desde" << ind[2].desde << endl;
		cout << "desde" << ind[3].desde << endl;
		*/

		// busqueda

		ifstream fOrigen(FileOrigen);
		if (fOrigen.fail()) {
			cerr << "Error al abrir el archivo: " << FileOrigen << endl; return 0;
		}
		ofstream fDestino(FileDestino);
		if (fDestino.fail()) {
			cerr << "Error al abrir el archivo: " << FileDestino << endl; return 0;
		}

		while (!fIDs.eof())
		{
			fIDs.getline(bloque, 33);

			IDDoc = atoll(bloque);
			//cout << IDDoc<<endl;
			if (IDDoc > 0)
			{
				//cout << "URL Encontrada"<<endl;
				fOrigen.seekg(ind[IDDoc - 1].desde);
				fOrigen.getline(bloqueOrigen, BLOQUELINEA, '\t');
				fDestino.write(bloqueOrigen, strlen(bloqueOrigen) * sizeof(char));
				fDestino.write("\n", sizeof(char));
				//cout << bloqueOrigen << endl;
			}
		}

		fIDs.close();

		fOrigen.close();
		fDestino.close();
	}
	return 0;
}