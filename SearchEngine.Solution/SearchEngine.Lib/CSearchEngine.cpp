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
	T_CHAR *bloque, *bloqueOrigen;
	bloque = new T_CHAR[33];
	bloqueOrigen = new T_CHAR[BLOQUELINEA];
	
	ifstream fOrigen(FileOrigen);
	if (fOrigen.fail()) {
		cerr << "Error al abrir el archivo: " << FileOrigen << endl; return 0;		
	}
	else
	{
		TIPOTAM i{ 0 }, k{ 1 }, j{ 0 }, l{ 0 }, IDDoc, desde, hasta;
		T_CHAR numero[33];
		T_CHAR ch;		
		Indice ind;
		ofstream fDestino(FileDestino, ios::binary);
		if (fDestino.fail()) {
			cerr << "Error al abrir el archivo: " << FileDestino << endl; return 0;			
		}
		ind.desde = 0;

		while (!fOrigen.eof())
		{			
			fDestino.write((T_CHAR *)(&ind), sizeof(Indice));				
			fOrigen.getline(bloqueOrigen, 32000, '\t');
			ind.desde = ind.desde + strlen(bloqueOrigen) + 1;		
		}
		fOrigen.close();
		fDestino.close();
	}
	return 0;
}


/*
* Se carga el archivo de entrada de IDs de los que se debe retornar URLs
*/

TIPOTAM CSearchEngine::CargarIds(T_CHAR *FileIDs, TIPOTAM *&IDs)
{
	TIPOTAM NroIDs = 0;
	T_CHAR *bloque;
	bloque = new T_CHAR[33];
	ifstream fIDs(FileIDs);
	if (fIDs.fail()){
		cerr << "Error al abrir el archivo: " << FileIDs << endl; return 0;
	}
	else{
		while (!fIDs.eof())	{
			fIDs.getline(bloque, 33);
			IDs[NroIDs++] = atoll(bloque);
		}
		fIDs.close();		
	}
	return --NroIDs;
}
/*
* Se carga el Indice de las URL
*/
TIPOTAM CSearchEngine::CargarIndexOrigen(T_CHAR *FileIndexOrigen, Indice *&ind) 
{	
	TIPOTAM tamIdArchivo{0};	
	ifstream fIndexOrigen(FileIndexOrigen, ios::binary);
	if (fIndexOrigen.fail()){
		cerr << "Error al abrir el archivo: " << FileIndexOrigen << endl; return 0;
	}
	else {
		tamIdArchivo = filesize(FileIndexOrigen) / sizeof(Indice);
		ind = new Indice[tamIdArchivo];
		ind[0].desde = 0;
		fIndexOrigen.read((T_CHAR *)(ind+1), sizeof(Indice)*(tamIdArchivo));
		fIndexOrigen.close();		
	}
	return tamIdArchivo;
}

/*
* Se carga el archivo de las URL
*/

void CSearchEngine::CargarFileOrigen(ifstream &fOrigen, T_CHAR *&mOrigen, TIPOTAM desde, TIPOTAM cantidad)
{	
	fOrigen.seekg(desde);
	fOrigen.read((T_CHAR *)(mOrigen), cantidad);
	mOrigen[cantidad] = '\0';		
}


T_INT CSearchEngine::CargarFileOrigen_2(T_CHAR *FileOrigen, T_CHAR *&mOrigen, TIPOTAM desde,TIPOTAM cantidad)
{
	ifstream fOrigen(FileOrigen);
	if (fOrigen.fail()) {
		cerr << "Error al abrir el archivo: " << FileOrigen << endl; return 0;
	}
	else {
		fOrigen.seekg(desde);
		fOrigen.read((T_CHAR *)(mOrigen), cantidad);
		mOrigen[cantidad] = '\0';
		fOrigen.close();
	}
	return 1;
}

/*
* Para hacer la busqueda de las URLs
*/
T_INT CSearchEngine::BuscarURLs(T_CHAR *FileIDs, T_CHAR *FileOrigen, T_CHAR *FileDestino, T_CHAR *FileIndexOrigen)
{
	T_CHAR *bloque, *mOrigen, *mDestino;;
	bloque = new T_CHAR[33];	
	mOrigen = new T_CHAR[BLOQUEMEMORIA];
	mDestino = new T_CHAR[BLOQUEMEMORIA];

	TIPOTAM *IDs, restofOrigen, restofDestino;
	IDs = new TIPOTAM[MAX_ID];
	TIPOTAM NroIDs = 0, tamfOrigen, tamfDestino, tamIdArchivo;

	NroIDs = CargarIds(FileIDs,IDs);
	
	if (NroIDs){	
		register TIPOTAM i{ 0 }, j{ 0 }, k{ 0 }, IDDoc;
		TIPOTAM	tamPagina{ TPAGINA };
		Indice *ind;
		tamIdArchivo = CargarIndexOrigen(FileIndexOrigen, ind);
		
		if(tamIdArchivo){
			tamfOrigen = filesize(FileOrigen);
			TIPOTAM desde{ 0 }, hasta{ 0 }, puntero{ 0 };

			ifstream fOrigen(FileOrigen);
			if (fOrigen.fail()) {
				cerr << "Error al abrir el archivo: " << FileOrigen << endl; return 0;
			}

			ofstream fDestino(FileDestino, ios::binary);
			if (fDestino.fail()) {
				cerr << "Error al abrir el archivo: " << FileDestino << endl; return 0;
			}						
			else{
				T_CHAR separador = '\t';
				
				while (i <= NroIDs){					
					IDDoc = IDs[(i++)-1];
					if (IDDoc <= tamIdArchivo){
						if (puntero <= IDDoc){
							desde = ind[IDDoc - 1].desde;
							puntero = IDDoc + tamPagina;
							if (puntero <= tamIdArchivo)
								hasta = ind[puntero - 1].desde;
							else {
								hasta = tamfOrigen; puntero = tamIdArchivo;
							}
							CargarFileOrigen(fOrigen, mOrigen, desde, hasta);	
						}

						if (IDDoc > 0){
							j = ind[IDDoc - 1].desde - desde;
							while (mOrigen[j] != separador)
								mDestino[k++] = mOrigen[j++];
							mDestino[k++] = '\n';
						}
					}
				}
				mDestino[k] = '\0';
				fDestino.write(mDestino, k);
				fDestino.close();
				fOrigen.close();
			}
		}
	}	
	return 0;
}
