#pragma once

#include <string>
<<<<<<< HEAD
=======
#include <cstring>
>>>>>>> master
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
<<<<<<< HEAD
=======
#include <vector>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <windows.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <cstdlib>
#include <thread>
>>>>>>> master
using namespace std;

// Type definitions 
typedef bool T_BOOL;
typedef char T_CHAR;
<<<<<<< HEAD
typedef unsigned int T_INT;
=======
typedef double T_DOUBLE;
typedef unsigned int T_INT;
typedef long long T_LONGLONG;
typedef long long TIPOTAM;
typedef const char T_CCHAR;

typedef	long T_LONG;
>>>>>>> master
typedef	long long MEMORY;
typedef	string FILE_NAME;
typedef	string _TOSEARCH_;
typedef	unsigned int ID_PAGE;
typedef	unsigned int POSITION;
typedef	unsigned int NUMBER_CHILD;
typedef	unsigned int NUMBER_LINES;
<<<<<<< HEAD

typedef ifstream READ_FILE;
typedef ofstream WRITE_FILE;
typedef map<int, string> URL_TABLE;
typedef pair<int, string> ID_URL;
typedef set<string> STOPWORD_TABLE;

typedef	string WORD;
typedef	string LINE;

#define SIZE 5;
=======
typedef	string WORD;

typedef ifstream READ_FILE;
typedef ofstream WRITE_FILE;
typedef map<int, string> URL_TABLE;
typedef pair<int, string> ID_URL;
typedef set<string> STOPWORD_TABLE;
typedef vector<string> V_STRING;
typedef	string T_WORD;
typedef	string LINE;
typedef	string T_STRING;

#define BLOQUELINEA (128'000)
#define BLOQUE (1'920)//1024+512+256+128)// tamaño donde se realiza la copia de manera algo mas rapida


const T_LONGLONG BLOQUELINEA = 128000;
const T_LONG BLOQUE = 1920;
const T_LONGLONG BLOQUEMEMORIA = 268435456; 
const T_LONGLONG MAX_ID = 4000000;
const T_LONGLONG TPAGINA = 750000;

#define SIZE 5;

struct Indice
{
	TIPOTAM desde;
};

struct lista
{
	T_INT id;
	vector<T_INT> contenido;
};
>>>>>>> master
