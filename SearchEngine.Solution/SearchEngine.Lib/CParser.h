#pragma once

#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/IParser.h"

class CParser : virtual public IParser {

private:
	READ_FILE file;
	FILE_NAME file_name;
	URL_TABLE url_table;
	STOPWORD_TABLE stop_words_list;

public:
	CParser(FILE_NAME);
	T_BOOL LoadStopWord(FILE_NAME);
	T_BOOL ParseFile();
	T_BOOL IsStopWord(WORD);
	T_BOOL IsMark(T_CHAR);
	T_BOOL IsMark(T_CHAR);
	T_BOOL NoMark(T_CHAR&);
	T_BOOL PreProcessWord(WORD);
	~CParser();
	//bool read(FILE_NAME);
};
