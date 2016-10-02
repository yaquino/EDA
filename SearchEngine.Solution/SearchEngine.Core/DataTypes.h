#pragma once

#include <string>
#include <fstream>
#include <map>
#include <set>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

// Type definitions 
typedef bool T_BOOL;
typedef char T_CHAR;
typedef unsigned int T_INT;
typedef	long long MEMORY;
typedef	string FILE_NAME;
typedef	string _TOSEARCH_;
typedef	unsigned int ID_PAGE;
typedef	unsigned int POSITION;
typedef	unsigned int NUMBER_CHILD;
typedef	unsigned int NUMBER_LINES;

typedef ifstream READ_FILE;
typedef ofstream WRITE_FILE;
typedef map<int, string> URL_TABLE;
typedef pair<int, string> ID_URL;
typedef set<string> STOPWORD_TABLE;

typedef	string WORD;
typedef	string LINE;

#define SIZE 5;