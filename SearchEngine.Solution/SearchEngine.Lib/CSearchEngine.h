#pragma once

#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/ISearchEngine.h"
#include "../SearchEngine.Core/IParser.h"
#include "../SearchEngine.Core/ITree.h"

#include "../SearchEngine.Lib/CParser.h"
#include "../SearchEngine.DataAccess/CTree.h"

class CSearchEngine : virtual public ISearchEngine {

public:
	CSearchEngine();
	~CSearchEngine();
	TIPOTAM CargarIds(T_CHAR *, TIPOTAM *&);
	TIPOTAM CargarIndexOrigen(T_CHAR *, Indice *&);
	void CargarFileOrigen(ifstream &, T_CHAR *&, TIPOTAM , TIPOTAM);
	T_INT BuscarURLs(T_CHAR *, T_CHAR *, T_CHAR *, T_CHAR *);
	T_INT IndexarURLs(T_CHAR *, T_CHAR *);
	T_INT funcion_Matching(FILE_NAME, FILE_NAME, FILE_NAME);
	T_INT compare(T_CHAR* , T_CHAR* );
	void split(T_STRING , T_CHAR , V_STRING &TempBuff, T_INT &);
	void Cuenta(T_STRING s, T_CCHAR Separadorr, T_INT &TotalChars);
	TIPOTAM filesize(T_CHAR[]);
	T_INT funcion_Copy(FILE_NAME, FILE_NAME);
};
