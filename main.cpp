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

#define HAMMING 1
#define EUCLIDIAN 2
#define COSINE 3

using namespace std;

void initTime();
double countDataFileham(ifstring, string);
int countDataFileEu(ifstring, string);
int getDataFiledim(ifstring, string);
string readDataFileham(ifstring, string);
double readDataFileEu(string, string*, int*, int*);
int readQueryFile(string, bool, string*);

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
		   
		int i = 0;
		int count = countDataFileham(file);
		string datasetham[count];

		ifstream file2(filePath);
		while (getline(file2, line)) {
		
			datasetham[i] = readDataFileham(file2, line);
			i++;
		}

	}
	else if (line.find("@metric_space euclidean") != string::npos) {
	
		int count = countDataFileEu(file);

			ifstream file2(filePath);

			int dim = getDataFiledim(file2)

				ifstream file3(filepath);

			double dataseteu[count][dim];

			getline(file3, line);
			getline(file3, line);

			int size;
			while (getline(file3, line)) {

				unsigned long pos = line.find_first_of("\t");
				line = line.substr(pos + 1);

				for (i = 0; i < dim; i++) {

					dataseteu[size][i] = readDataFileEu(file3, line)
				}

				size++;
			}
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

	while (line.find_first_of("\t") != 1) {
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
int readQueryFile(string filePath, int calledFor, string *dataArray, int id) {
    ifstream file(filePath);
    string line;
    
    getline(file, line);
    unsigned long pos = line.find_first_of(" ");
    
    line = line.substr(pos+1);
    const int radius = stoi(line);
    
    getline(file, line);
    
    if (id == HAMMING) {
        if (calledFor == 1) {
            int count = 0;
            
            while (getline(file, line)) {
                count++;
            }
            
            return count;
        }
        else {
            int index = 0;
            
            while (getline(file, line)) {
                unsigned long pos = line.find_first_of("\t");
                line = line.substr(pos+1);
                
                dataArray[index] = line;
                index++;
            }
            
            return 0;
        }
    }
    else if (line.find("@metric_space euclidean") != string::npos) {
        int count = 0;
        
        while (getline(file, line)) {
            count++;
        }
        
        // ----------------------
        
        ifstream file(filePath);
        string line;
        
        int dim = 0;
        getline(file, line);
        
        while (line != "!\n") {
            unsigned long pos = line.find_first_of("\t");
            line = line.substr(pos+1);
            
            dim++;
        }
        
        // ----------------------
        
        ifstream file2(filePath);
        string line2;
        getline(file2, line2);
        
        int index = 0;
        string **queryPoints = new string*[count];
        int size;
        
        for (size = 0; size < count; size++) {
            queryPoints[size] = new string[dim];
        }
        
        size = 0;
        
        while (getline(file2, line2)) {
            int i;
            line2 = line2.substr(pos+1);

            for (i = 0; i < dim; i++) {
                unsigned long pos = line.find_first_of("\t");
                
                queryPoints[size][i] = line2.substr(0, pos);
                line2 = line2.substr(pos+1);
                
                index++;
            }
            
            size++;
        }
        
        return 0;
    }
    return 0;
}
