/*
 * compiler.cpp
 *
 *  Created on: 14/06/2017
 *      Author: jamie
 */

#include "compiler.h"

Lexer::Lexer(string filename) {
	this->filename = filename;
}

string Lexer::getFilename() {
	return this->filename;
}

void Lexer::setFilename(string filename) {
	this->filename = filename;
}

bool Lexer::isComment(string line) {
	return ((line[0] == '/') && (line[1] == '/'));
}

void Lexer::printFile() {
	//this->file.open(this->filename);

	string line;
	ifstream file;

	file.open(this->filename);

	if (file.is_open()) {
		while(!file.eof()) {
			getline(file, line);
			if (!this->isComment(line)) {
				cout << line << endl;
			}
		}
	}
	else {
		cout << "Could not open file" << endl;
		exit(1); //Terminate with error
	}

	file.close();

	/*string line;
	ifstream file;*/


}


