#include <iostream>
#include <string.h>
#include <string>
#include "datafile.hpp"

using namespace std;

//----------------------------data files----------------------------//

int countDataFileHam(ifstream &file, string line) {
    int count = 0;

    while (getline(file, line)) {
        count++;
    }

    return count;
}

string readDataFileHam(ifstream  &file, string line) {
    unsigned long pos = line.find_first_of("\t");
    line = line.substr(pos+1);

    return line;
}

int countDataFileEu(ifstream &file, string line) {
	int count = 0;
	getline(file, line);

	while (getline(file, line)) {
		count++;
	}

	return count;
}

int getDataFileDim(ifstream &file, string line) {
    string previousSubstring;

    int dim = 0;

	getline(file, line);
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

double ConvertFileEu(string line, unsigned long pos) {
    double queryPointsArray;
    queryPointsArray = stod(line.substr(0, pos));

    pos = line.find_first_of("\t");
    line = line.substr(pos+1);

    return queryPointsArray;
}

string readDataFileEu(ifstream  &file, string line) {

	unsigned long pos = line.find_first_of("\t");
    line = line.substr(pos+1);

    return line;
}
