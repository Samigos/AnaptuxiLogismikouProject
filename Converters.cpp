#include <iostream>
#include <string>
#include "Converters.hpp"

using namespace std;

double ConvertStringtolonglong(string a) {
	double num;
    num = stod(a);

	return num;
}

double ConvertFileEu(string line, unsigned long pos) {
    double queryPointsArray;
    queryPointsArray = stod(line.substr(0, pos));
    
    return queryPointsArray;
}
