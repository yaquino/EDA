#pragma once

#include "../SearchEngine.Core/DataTypes.h"
#include "../SearchEngine.Core/IParser.h"

class CParser : virtual public IParser {

private:

	READ_FILE file;
	WRITE_FILE out_file;
	FILE_NAME input_file; // name of the file containing the documents
	FILE_NAME url_file; // name of the file where the id-url pairs are stored
	URL_TABLE url_table;
	STOPWORD_TABLE stop_words_list;

public:
	CParser() {};
	CParser(FILE_NAME, FILE_NAME);
	T_BOOL LoadStopWord(FILE_NAME);
	T_BOOL ParseFile();
	T_BOOL IsStopWord(T_WORD);
	T_BOOL IsMark(T_CHAR);
	T_BOOL NoMark(T_CHAR&);
	T_BOOL PreProcessWord(T_WORD&);
	~CParser();
};