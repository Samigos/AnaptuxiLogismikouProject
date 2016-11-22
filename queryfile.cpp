/*
 * queryfile.cpp
 *
 *  Created on: Nov 22, 2016
 *      Author: Zeaniel
 */

#include <iostream>
#include <string.h>
#include <string>
#include "queryfile.hpp"

using namespace std;

//----------------------------query files----------------------------//

int countQueryFileHam(ifstream &file, string line) {
	int count = 0;

	while (getline(file, line)) {
		count++;
	}

	return count;
}

string readQueryFileHam(ifstream &file, string line) {
	unsigned long pos = line.find_first_of("\t");
	line = line.substr(pos + 1);

	return line;
}

int countQueryFileEu(ifstream &file, string line) {
	int count = 0;

	while (getline(file, line)) {
		count++;
	}

	return count;
}

int getQueryFileDim(ifstream &file, string line) {
	string previousSubstring;

    int dim = 0;

	getline(file, line);
	getline(file, line);

	while (line.find_first_of("\t") != -1) {
		const unsigned long pos = line.find_first_of("\t");

		if (pos == -1) {
			break;
		}

		line = line.substr(pos + 1);
		dim++;
	}

	return dim;
}

double readQueryFileEu(ifstream &file, string line, unsigned long pos) {
    double queryPointsArray;
    queryPointsArray = stod(line.substr(0, pos));

	pos = line.find_first_of("\t");
	line = line.substr(pos + 1);

	return queryPointsArray;
}

int radiusQueryFile(string line){

	int radius;
	const unsigned long pos = line.find_first_of("\t");
	line = line.substr(pos + 1);

	radius = stoi(line);

	return radius;
}
