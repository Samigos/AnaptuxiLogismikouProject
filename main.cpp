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
		
		int results[countd];
		int j,o;

		for (q = 0; q < countq; q++) {

			
			for (w = 0; w < (2 ^ k); w++) {

				
				int dis = hamming_distance(querysetHam[q],hashTable[q].getHeads(w));
			
				if (radius > dis) {

							results = hashTable[q].getBody(w);
							cout << "kontinoteros geitonas" << hashTable[q].getHeads(w) << endl;

							int min = dis);
							for (o = 1; o < countd; o++){

									int dis = hamming_distance(querysetHam[q],results[o]);

									if(dis < min){

										min = dis;
									}
							}

							cout << "True kontinoteros geitonas"  << min << endl;

				}

			}

		}
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
	
	   int** Geuc;	// deikths gia ton diplo pinaka ths euclidean
	        int q, w, e, v, A;
	        Geuc = G(k, L, EUCLIDEAN);
	        
	        for (q = 0; q < L; q++) {

	        		for (w = 0; w < (2 ^ k); w++) {

	        				e = Geuc[q][w];
	        				hashTable[q].addBitString(datasetEu[e - 1]);
	        			}
	        }

	        double dataEu[L][2 ^ k ][dataDim];

	        for (q = 0; q < L; q++){

	        		for (w = 0; w < (2 ^ k); w++)

	        				pos = (hashTable[q].getHeads(w)).find_first_of("\t");

	        				for(v = 0; v < dataDim; v++){

	        						dataEu[q][w][v] = ConvertFileEu(hastTable[q].getHeads(w), pos);
	        				}

	        }
	       //int dis = hamming_distance(querysetHam[0],hashTable[0].getHeads(0));
	        		//int min = dis;
	        double results[countd][dataDim];
	        double J, minq;
	        string* dataeustr = new string[L][2 ^ k][countd];
	        unsigned long pos1[dataDim];
	        e = 0;
	        int K;
	        for (q = 0; q < L; q++){

	        	for (w = 0; w < (2 ^ k); w++){

	        		//pos1[w] = (hashTable[q].getHeads(w)).find_first_of("\t");

	        		for (v = 0; v < countq; v++){

	        				J = distanceCalculate(dataEu, querySetEu, q, w, dataDim, v, queryDim);

	        				if(radius > J){

	        					dataeustr[q][w] = hashTable[q].getBody(w);
	        					while(dataeustr[q][w][e] != NULL)

	        						while (A < dataDim) {

	        							pos1[w] = (dataeustr[q][w][e].find_first_of("\t"));

	        								J = ConvertFileEu(dataeustr[q][w][e], pos1[w]);
	        								dataeustr[q][w][e] = dataeustr[q][w][e].substr(pos1[w] + 1);

	        								results[e][A] = J;
	        								A++;
	        						}

	        					e++;
	        					}


	        						cout << "kontinoteros geitonas" << results[e][0] << endl;

	        				}


	        				if (radius > J){

	        					for(K = 0; K < e; K++){

	        						min = results[K][0];

	        						for (A = 1; A < dataDim; A++){

	        							if (min > results[K][A]){

	        								min = results[K][A];
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

