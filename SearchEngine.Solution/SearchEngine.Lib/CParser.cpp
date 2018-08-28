#include "CParser.h"

CParser::CParser(FILE_NAME input, FILE_NAME output) : input_file(input), url_file(output) {}

T_BOOL CParser::LoadStopWord(FILE_NAME stop_word_file) {
	READ_FILE swfile;
	swfile.open(stop_word_file);
	if (swfile.is_open()) {

		T_WORD word;

		while (!swfile.eof()) {
			swfile >> word;
			stop_words_list.insert(word);
		}
		swfile.close();
		return true;
	}
	return false;
}

/*
Main function
Gets the documents file and generates the entries to be indexed by the structure.
Assigns an ID to each document and creates an url table to match IDs and urls.
*/
T_BOOL CParser::ParseFile() {
	file.open(input_file);
	if (file.is_open()) {

		LoadStopWord("stopwords.txt");
		T_INT document_id = 1;
		T_INT document_block;
		LINE url, content;
		T_WORD word;
		istringstream iss;

		/*
		This loop  reads the documents one by one:
		First Line  contains the url to the document.
		Second Line contains the title of the document.
		Next lines contain the document paragraphs, till an empty line.
		*/
		while (!file.eof()) {
			document_block = 0;
			getline(file, url);
			/*
			A document id is assigned to each document and this id is stored in a table with the corresponding url
			*/
			url_table.insert(*(new ID_URL(document_id, url)));
			/*
			This loop iterates each paragraph(block) of a document.
			*/
			do {
				++document_block;
				getline(file, content);
				iss.str(content);
				/*
				This loop reads the current block by word and calls functions to preprocess and insert to tree.
				*/
				while (iss >> word) {
					PreProcessWord(word);
					if (!IsStopWord(word) && !word.empty()) {
						//Out << document_id << "\t\t" << document_block << "\t\t" << word << endl;;
					}
				}

				iss.clear();
			} while (!content.empty());
			++document_id;
			document_block = 0;
		}
	}

	file.close();
	/*
	The url_table is written on a file in order to map the urls to their corresponding IDs during the search function.
	*/
	out_file.open(url_file);
	if (out_file.is_open()) {
		URL_TABLE::iterator map_it;
		for (map_it = url_table.begin(); map_it != url_table.end(); ++map_it) {
			out_file << map_it->first << "\t" << map_it->second << endl;
		}
		out_file.close();
		return true;
	}

	cout << "Unable to open file";
	return false;
}

/*
Before inserting a word into the structure,
each word is set to lowcase and marks are eliminated
(e.g. punctuaction signs, á, ñ, etc)
*/
T_BOOL CParser::PreProcessWord(T_WORD &word) {

	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
	for (T_INT i = 0; i < word.length(); ++i) {
		if (IsMark(word[i])) {
			word.erase(i, 1);
			while (i < word.length() && !NoMark(word[i])) {
				word.erase(i, 1);
			}
		} if (i < word.length() && !isalpha(word[i]) && !isdigit(word[i])) {
			word.erase(i, 1);
		}
	}
	return true;
}
T_BOOL CParser::IsStopWord(T_WORD word) {

	return stop_words_list.find(word) != stop_words_list.end();
}
T_BOOL CParser::IsMark(T_CHAR in) {
	return (in < 0);
}
T_BOOL CParser::NoMark(T_CHAR &in) {
	switch (in) {
	case -95:
		in = 'a';
		break;
	case -87:
		in = 'e';
		break;
	case -83:
		in = 'i';
		break;
	case -77:
		in = 'o';
		break;
	case -70:
		in = 'u';
		break;
	case -79:
		in = 'n';
		break;
	default:
		return false;
	}
	return true;
}
CParser::~CParser() {}