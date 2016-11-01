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

//----------------------------data files----------------------------/

void initTime();
int countDataFileham(ifstring, string);
int countDataFileEu(ifstring, string);
int getDataFiledim(ifstring, string);
string readDataFileham(ifstring, string);
double readDataFileEu(ifstring, string);

//----------------------------query files----------------------------//

int countQueryFileham(ifstring, string);
int countQueryFileEu(ifstring, string);
int getQueryFiledim(ifstring, string);
string readQueryFileham(ifstring, string);
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

	ifstream file(filePath);
	string line;
	int i;

	getline(file, line);
	if (line.find("@metric_space hamming") != string::npos) {
		   
		int countd = countDataFileham(file);

		string datasetham[countd];

		ifstream file2(filePath);
		while (getline(file2, line)) {
		
			datasetham[i] = readDataFileham(file2, line);
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

			int datadim = getDataFiledim(file2)

			ifstream file3(filepath);

			double dataseteu[countd][datadim];

			getline(file3, line);
			getline(file3, line);

			int size;
			while (getline(file3, line)) {

				unsigned long pos = line.find_first_of("\t");
				line = line.substr(pos + 1);

				for (i = 0; i < datadim; i++) {

					dataseteu[size][i] = readDataFileEu(file3, line)
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

			int querydim = getDataFiledim(file4)

			ifstream file5(filepath);

			double queryseteu[countq][querydim];
			
			getline(file5, line);

			int size;
			while (getline(file5, line)) {

				unsigned long pos = line.find_first_of("\t");
				line = line.substr(pos + 1);

				for (i = 0; i < datadim; i++) {

					queryseteu[size][i] = readQueryFileEu(file5, line)
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
int countDataFileham(ifstring file, string line) {
	
		int count = 0;

		while (getline(file, line)) {
			count++;
		}
		return count;
	}

string readDataFileham(ifstring file, string line) {

            unsigned long pos = line.find_first_of("\t");
            line = line.substr(pos+1);
			
			return line;
        }
int countDataFileEu(ifstring file, string line) {
	
	int count = 0;
	getline(file, line);

	while (getline(file, line)) {
		count++;
	}
	
	return count;
    
}
int getDataFiledim(ifstring file, string line) {

	string line;
	int dim = 0;
	string previousSubstring;

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
double readDataFileEu(ifstring file, string line){
            
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
int  countQueryFileham(ifstring file, string line) {

	int count = 0;

	while (getline(file, line)) {
		count++;
	}
	return count;
}

string readQueryFileham(ifstring file, string line) {

	unsigned long pos = line.find_first_of("\t");
	line = line.substr(pos + 1);

	return line;
}
int countQueryFileEu(ifstring file, string line) {

	int count = 0;

	while (getline(file, line)) {
		count++;
	}

	return count;

}
int getQueryFiledim(ifstring file, string line) {

	string line;
	int dim = 0;
	string previousSubstring;

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
double readQueryFileEu(ifstring file, string line) {

	//cout << stod(line2, &fred) << endl;

	cout << stod(line.substr(0, pos)) << endl;
	queryPointsArray = stod(line.substr(0, pos));

	pos = line.find_first_of("\t");
	line = line.substr(pos + 1);

	return queryPointsArray;
}
