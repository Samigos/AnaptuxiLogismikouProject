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
#include "Hamming.hpp"
#include "Converters.hpp"
#include "datafile.hpp"
#include "Euclidian.hpp"
#include "Ghash.hpp"
#include "SKAWriteToFile.hpp"

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
				hashTable[q].addBitString(datasetHam[e - 1]); // mipws datasetHam[e]?
			}
		}
		
		string *results = new string[countd];
		int o;
        
        ofstream file;
        SKACreateFile(file, "output.txt");

        for (q = 0; q < countq; q++) {
            string queryItemHeader = "Query: ";
            
            string item = "item";
            item += q;
            
            SKAWriteToFile(file, queryItemHeader + item);
            SKAWriteToFile(file, "R-near neighbors:");

			for (w = 0; w < (2 ^ k); w++) {
				int dis = hamming_distance(querysetHam[q], hashTable[q].getHeads(w));
			
                if (radius > dis) { // >= ???
                    SKAWriteToFile(file, item);
                    
                    results = hashTable[q].getBody(w); // to xreiazomaste???
                    cout << "kontinoteros geitonas" << hashTable[q].getHeads(w) << endl;
                    
                    int min = dis;
                    
                    for (o = 1; o < countd; o++) {
                        int dis = hamming_distance(querysetHam[q], results[o]);

                        if (dis < min) {
                            min = dis;
                        }
                    }

                    //SKAWriteToFile(file, "Nearest neighbor: " + "item");
                    cout << "True kontinoteros geitonas " << min << endl;
                }
			}
		}
        
        SKACloseFile(file);
    }
	else if (line.find("@metric_space euclidean") != string::npos) {
		int countd = countDataFileEu(file, line);
        ifstream file2(filePath);

        int dataDim = getDataFileDim(file2, line);
        ifstream file3(filePath);

        string *datasetEu = new string[countd];

        getline(file3, line);
        getline(file3, line);

        int size = 0;
        
        while (getline(file3, line)) {
            datasetEu[size] = readDataFileEu(file3, line);
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
        
        // ---------------------------
        
        double** querySetEu = new double*[countq];
        
        for (i = 0; i < queryDim; i++)
            querySetEu[i] = new double[queryDim];
        
        getline(file5, line);
        
        // ---------------------------
        
        size = 0;
        
        while (getline(file5, line)) {
            unsigned long pos = line.find_first_of("\t");
            line = line.substr(pos + 1);

            for (i = 0; i < dataDim; i++) {
                querySetEu[size][i] = readQueryFileEu(file5, line, pos);
            }
            
            size++;
        }
        
        //------------ diavasma query------------//
        
        int** Geuc;	// deikths gia ton diplo pinaka ths euclidean
        int h, w, e, v, A;
        Geuc = G(k, L, EUCLIDEAN);
        
        for (h = 0; h < L; h++) {
            for (w = 0; w < (2 ^ k); w++) {
                e = Geuc[h][w];
                hashTable[h].addBitString(datasetEu[e - 1]);
            }
        }
        
        double ***dataEu = new double**[L];
        
        for (h = 0; h < (2 ^ k); h++) {
            dataEu[h] = new double*[2 ^ k];
            
            for (w = 0; w < dataDim; w++)
                dataEu[h][w] = new double[dataDim];
        }
        
        // ---------------------------
        
        for (h = 0; h < L; h++) {
            for (w = 0; w < (2 ^ k); w++) {
                pos = (hashTable[h].getHeads(w)).find_first_of("\t");
                
                for (v = 0; v < dataDim; v++) {
                    dataEu[h][w][v] = ConvertFileEu(hashTable[h].getHeads(w), pos);
                }
            }
        }
        
        // ---------------------------
        
        double results[countd][dataDim];
        double J, minq;
        
        string ***dataeustr = new string**[L];
        
        for (h = 0; h < (2 ^ k); h++) {
            dataeustr[h] = new string*[2 ^ k];
            
            for (w = 0; w < countd; w++)
                dataeustr[h][w] = new string[countd];
        }
        
        // ---------------------------
        
        unsigned long pos1[dataDim];
        int K;
        
        e = 0;
        
        for (h = 0; h < L; h++) {
            for (w = 0; w < (2 ^ k); w++) {
                for (v = 0; v < countq; v++) {
                    J = distanceCalculate(dataEu, querySetEu, h, w, dataDim, v, queryDim);
                    
                    if (radius > J) {
                        dataeustr[h][w] = hashTable[h].getBody(w);
                        
                        while (dataeustr[h][w] != NULL) {
                            while (A < dataDim) {
                                pos1[w] = (dataeustr[h][w][e].find_first_of("\t"));
                                
                                J = ConvertFileEu(dataeustr[h][w][e], pos1[w]);
                                dataeustr[h][w][e] = dataeustr[h][w][e].substr(pos1[w] + 1);
                                
                                results[e][A] = J;
                                A++;
                            }
                        }
                        
                        e++;
                    }
                    
                    cout << "kontinoteros geitonas" << results[e][0] << endl;
                }
                
                if (radius > J) {
                    for (K = 0; K < e; K++) {
                        minq = results[K][0];
                        
                        for (A = 1; A < dataDim; A++) {
                            if (minq > results[K][A]) {
                                minq = results[K][A];
                            }
                        }
                    }
                }
                
                e = 0;
            }
        }
    }

    return 0;
}

void initTime() {
    long currentTime = time(NULL);
    srand((unsigned int) currentTime);
}

