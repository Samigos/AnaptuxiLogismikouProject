//
//  main.cpp
//  ALProject
//
//  Created by Sotiris Kaniras on 14/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>
#include <sstream>
#include <fstream>
#include "SKAHashTable.hpp"
#include "Converters.hpp"

#define HAMMING 1
#define EUCLIDEAN 2
#define COSINE 3

using namespace std;

//----------------------------data files----------------------------//

void initTime();
int countDataFileHam(ifstream&, string);
int countDataFileEu(ifstream&, string);
int getDataFileDim(ifstream&, string);
string readDataFileHam(ifstream&, string);
double readDataFileEu(ifstream&, string, unsigned long);

//----------------------------query files----------------------------//

int countQueryFileHam(ifstream&, string);
int countQueryFileEu(ifstream&, string);
int getQueryFileDim(ifstream&, string);
string readQueryFileHam(ifstream&, string);
double readQueryFileEu(ifstream&, string, unsigned long);

//----------------------------Main----------------------------//


int main(int argc, const char *argv[]) {
    int k = 4, L = 5, index;
    string d, q, o;
    
    for (index = 1; index < argc; index++) {
        if (strcmp(argv[index], "-d") == 0) {
            d = string(argv[index+1]);
        }
        else if (strcmp(argv[index], "-q") == 0) {
            q = string(argv[index+1]);
        }
        else if (strcmp(argv[index], "-k") == 0) {
            k = atoi(argv[index+1]);
        }
        else if (strcmp(argv[index], "-L") == 0) {
            L = atoi(argv[index+1]);
        }
        else if (strcmp(argv[index], "-o") == 0) {
            o = string(argv[index+1]);
        }
    }
    
    initTime();
    SKAHashTable *hashTable = new SKAHashTable[L];

    
    for (index = 0; index < L; index++) {
        hashTable[index].init(k);
    }
    
    // -----------------------------------------------
    
    string filePath = d;
    
	ifstream file(filePath);
	string line;
	int i;
    
	getline(file, line);
	if (line.find("@metric_space hamming") != string::npos) {
		int countd = countDataFileHam(file, line);
		string *datasetHam = new string[countd];
		ifstream file2(filePath);

		while (getline(file2, line)) {
			datasetHam[i] = readDataFileHam(file2, line);
			i++;
		}

		//------------ diavasma dataset------------//

		ifstream file3(filePath);
		getline(file3, line);
		unsigned long pos = line.find_first_of(" ");

		line = line.substr(pos + 1);
		const int radius = stoi(line);

		i = 0;

		int countq = countQueryFileHam(file3, line);
		string *querysetHam = new string[countq];

		ifstream file4(filePath);

		while (getline(file4, line)) {
			querysetHam[i] = readDataFileHam(file2, line);
			i++;
		}


		//------------ diavasma query------------//

		int** Gham;
		int q, w, e;
		Gham = G(k, L, countd, HAMMING);

		for (q = 0; q < L; q++) {
			for (w = 0; w < (2 ^ k); w++) {
				e = Gham[q][w];

				hashTable[q].addBitString(datasetHam[e - 1]);
			}
		}
		long long sotos = ConvertStringtolonglong(querysetHam[0]);
		int sotakos = convertBinaryToDecimal(sotos);
		long long stavros = ConvertStringtolonglong(hashTable[0].getHeads(0));
		int stavrakos = convertBinaryToDecimal(stavros);

		if (stavrakos > sotakos) {

			bitnumb = stavrakos - sotakos;
		}
		else {
			bitnumb = sotakos - stavrakos;
		}

		int min = bitnumb;
		long long results[(2 ^ k)*L];
		int J = 1;

		for (q = 1; q < countq; q++) {

			sotos = ConvertStringtolonglong(querysetHam[q]);
			sotakos = convertBinaryToDecimal(sotos);   //metatroph tou binary se arithmo
			int bitnumb;
			for (w = 1; w < (2 ^ k); w++) {

				stavros = ConvertStringtolonglong(hashTable[q].getHeads(w));
				stavrakos = convertBinaryToDecimal(stavros);

				if (stavrakos > sotakos) {

					bitnumb = stavrakos - sotakos;
				}
				else {
					bitnumb = sotakos - stavrakos;
				}
				if (radius > bitnumb) {

					if (min > bitnumb) {


						results[J] = min;
						min = bitnumb;
						J++;

					}
					else {
						results[J] = bitnumb;
						J++;

					}

				}
			}
		}

		results[0] = min;

	}


	else if (line.find("@metric_space euclidean") != string::npos) {
		int countd = countDataFileEu(file, line);
        ifstream file2(filePath);

        int dataDim = getDataFileDim(file2, line);
        ifstream file3(filePath);

        double datasetEu[countd][dataDim];

        getline(file3, line);
        getline(file3, line);

        int size = 0;
        
        while (getline(file3, line)) {
            unsigned long pos = line.find_first_of("\t");
            line = line.substr(pos + 1);

            for (i = 0; i < dataDim; i++) {
                datasetEu[size][i] = readDataFileEu(file3, line, pos);
            }

            size++;
        }
        
        //------------ diavasma dataset------------//

        ifstream file4(filePath);
        getline(file4, line);
        unsigned long pos = line.find_first_of(" ");

        line = line.substr(pos + 1);
        const int radius = stoi(line);

        i = 0;

        int countq = countQueryFileEu(file4, line);
        ifstream file6(filePath);

        int queryDim = getDataFileDim(file6, line);
        ifstream file5(filePath);

        double querySetEu[countq][queryDim];
        getline(file5, line);

        size = 0;
        
        while (getline(file5, line)) {
            unsigned long pos = line.find_first_of("\t");
            line = line.substr(pos + 1);

            for (i = 0; i < dataDim; i++) {
                querySetEu[size][i] = readQueryFileEu(file5, line, pos);
            }

            size++;
        }
        //------------ diavasma querry------------//
	}
   
    return 0;

	      
}

void initTime() {
    long currentTime = time(NULL);
    srand((unsigned int) currentTime);
}

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

double readDataFileEu(ifstream &file, string line, unsigned long pos) {
    double queryPointsArray;
    queryPointsArray = stod(line.substr(0, pos));
    
    pos = line.find_first_of("\t");
    line = line.substr(pos+1);

    return queryPointsArray;
}
   /* else if (line.find("@metric_space cosine") != string::npos) {
        id = COSINE;
        
        string currentLine = line;
        getline(file, line);
        
        while (getline(file, line)) {
            unsigned long pos = line.find_first_of("\t");
            line = line.substr(pos+1);
            
            cout << line << endl;
        }
    }
    
    return 0;
}
*/

//--------------------------------------
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
