/*
 * compiler.h
 *
 *  Created on: 14/06/2017
 *      Author: jamie
 *
 *      Used to create user-defined commands
 *      I am reading http://www.diku.dk/~torbenm/Basics/basics_lulu2.pdf
 *
 *      We need to perform lexical analysis to convert our commands into tokens, to be processed
 *
 *      We could also think of the processing of user commands as being interpreted
 */

#ifndef COMPILER_COMPILER_H_
#define COMPILER_COMPILER_H_

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Lexer {
	private:
		string filename;
	public:
		Lexer(string filename);
		string getFilename();
		void setFilename(string filename);
		bool isComment(string line);
		void printFile();
};

class Parser {

};


#endif /* COMPILER_COMPILER_H_ */
