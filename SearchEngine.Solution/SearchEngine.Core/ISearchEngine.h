#pragma once

#include "DataTypes.h"

class ISearchEngine {
public:
	virtual T_INT BuscarURLs(T_CHAR *, T_CHAR *, T_CHAR *, T_CHAR *) = 0;
	virtual T_INT IndexarURLs(T_CHAR *, T_CHAR *) = 0;
	virtual T_INT funcion_Matching(FILE_NAME, FILE_NAME, FILE_NAME) = 0;
	virtual T_INT compare(T_CHAR*, T_CHAR*) = 0;
	virtual void split(T_STRING, T_CHAR, V_STRING &TempBuff, T_INT &) = 0;
	virtual void Cuenta(T_STRING s, T_CCHAR Separadorr, T_INT &TotalChars) = 0;
	virtual TIPOTAM filesize(T_CHAR[]) = 0;
	virtual T_INT funcion_Copy(FILE_NAME, FILE_NAME) = 0;
};
