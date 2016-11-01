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


using namespace std;

//----------------------------data files----------------------------//

void initTime();
int countDataFileHam(ifstream, string);
int countDataFileEu(ifstream, string);
int getDataFileDim(ifstream, string);
string readDataFileHam(ifstream, string);
double readDataFileEu(ifstream, string);

//----------------------------query files----------------------------//

int countQueryFileHam(ifstream, string);
int countQueryFileEu(ifstream, string);
int getQueryFileDim(ifstream, string);
string readQueryFileHam(ifstream, string);
double readQueryFileEu(string, string*, int*, int*);
int readQueryFile(string, bool, string*);

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
		string datasetham[countd];

		ifstream file2(filePath);
        
		while (getline(file2, line)) {
		
			datasetham[i] = readDataFileHam(file2, line);
			i++;
		}
		//------------ diavasma dataset------------//
		
		ifstream file3(filePath);
		getline(file3, line);
		unsigned long pos = line.find_first_of(" ");

		line = line.substr(pos + 1);
		const int radius = stoi(line);
		
		i = 0;
		int countq = countQueryFileham(file3); 

		string querysetham[countq];

		ifstream file4(filePath);
		while (getline(file4, line)) {

			querysetham[i] = readDataFileham(file2, line);
			i++;
		}
		//------------ diavasma query------------//


	}
	else if (line.find("@metric_space euclidean") != string::npos) {
		int countd = countDataFileEu(file);
        ifstream file2(filePath);

        int dataDim = getDataFileDim(file2)
        ifstream file3(filepath);

        double datasetEu[countd][datadim];

        getline(file3, line);
        getline(file3, line);

        int size;
        while (getline(file3, line)) {
            unsigned long pos = line.find_first_of("\t");
            line = line.substr(pos + 1);

            for (i = 0; i < dataDim; i++) {
                datasetEu[size][i] = readDataFileEu(file3, line)
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

        int countq = countQueryFileEu(file4);
        ifstream file4(filePath);

        int queryDim = getDataFiledim(file4)
        ifstream file5(filepath);

        double querySetEu[countq][querydim];
        getline(file5, line);

        int size;
        while (getline(file5, line)) {
            unsigned long pos = line.find_first_of("\t");
            line = line.substr(pos + 1);

            for (i = 0; i < datadim; i++) {
                querySetEu[size][i] = readQueryFileEu(file5, line)
            }

            size++;
        }
        //------------ diavasma dataset------------//
	}
   
    return 0;

	      
}

void initTime() {
    long currentTime = time(NULL);
    srand((unsigned int) currentTime);
}

int countDataFileHam(ifstream file, string line) {
    int count = 0;

    while (getline(file, line)) {
        count++;
    }

    return count;
}

string readDataFileHam(ifstream file, string line) {
    unsigned long pos = line.find_first_of("\t");
    line = line.substr(pos+1);
    
    return line;
}

int countDataFileEu(ifstream file, string line) {
	int count = 0;
	getline(file, line);

	while (getline(file, line)) {
		count++;
	}
	
	return count;
}

int getDataFileDim(ifstream file, string line) {
	string line;
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

double readDataFileEu(ifstream file, string line) {
    
    //cout << stod(line2, &fred) << endl;

    cout << stod(line.substr(0, pos)) << endl;
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
int countQueryFileHam(ifstream file, string line) {
	int count = 0;

	while (getline(file, line)) {
		count++;
	}
    
	return count;
}

string readQueryFileHam(ifstream file, string line) {
	unsigned long pos = line.find_first_of("\t");
	line = line.substr(pos + 1);

	return line;
}

int countQueryFileEu(ifstream file, string line) {
	int count = 0;

	while (getline(file, line)) {
		count++;
	}

	return count;

}

int getQueryFileDim(ifstream file, string line) {
	string line;
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

double readQueryFileEu(ifstream file, string line) {
	cout << stod(line.substr(0, pos)) << endl;
	queryPointsArray = stod(line.substr(0, pos));

	pos = line.find_first_of("\t");
	line = line.substr(pos + 1);

	return queryPointsArray;
}
