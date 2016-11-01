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

double** readDataFile(string, string*, int*, int*);
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
    
    for (index = 0; index < L; index++) {
        hashTable[index].init(k);
    }
    
    int *queryPointsArrayRows, *queryPointsArrayColumns;
    double **dataArray = readDataFile(d, NULL, queryPointsArrayRows, queryPointsArrayColumns);
    
    if (dataArray != NULL) {
        int rows, columns;
        int i, j;
        
        rows = *queryPointsArrayRows;
        columns = *queryPointsArrayColumns;
        
        for (i = 0; i < rows; i++) {
            for (j = 0; j < columns; j++) {
                cout << dataArray[i][j] << endl;
            }
            
            cout << "\n" << endl;
        }
    }
    
    return 0;
}

void initTime() {
    long currentTime = time(NULL);
    srand((unsigned int) currentTime);
}

double** readDataFile(string filePath, string *dataArray, int *queryPointsArrayRows, int *queryPointsArrayColumns) {
    ifstream file(filePath);
    string line;
    int id = 0;
    
    getline(file, line);
    
    if (line.find("@metric_space hamming") != string::npos) {
        id = HAMMING;
        
        int arraySize = 0;
        
        while (getline(file, line)) {
            arraySize++;
        }
        
        dataArray = new string[arraySize];
        
        // ----------------------
        
        int index = 0;
        
        while (getline(file, line)) {
            unsigned long pos = line.find_first_of("\t");
            line = line.substr(pos+1);
            
            dataArray[index] = line;
            index++;
        }
        
        return NULL;
    }
    else if (line.find("@metric_space euclidean") != string::npos) {
        id = EUCLIDIAN;
        
        int count = 0;
        getline(file, line);
        
        while (getline(file, line)) {
            count++;
        }
        cout << count << endl;
        // --------------------------------------------
        
        ifstream file(filePath);
        string line;
        
        int dim = 0;
        string previousSubstring;
        
        getline(file, line);
        getline(file, line);
        getline(file, line);
        
        while (line != "!\n") {
            const unsigned long pos = line.find_first_of("\t");
            
            if (pos == -1) {
                break;
            }
            
            line = line.substr(pos+1);
            dim++;
        }
        cout << dim << endl;
        // --------------------------------------------
        
        ifstream file2(filePath);
        string line2;
        
        getline(file2, line2);
        getline(file2, line2);
        
        int size;
        double **queryPointsArray = new double*[count];
        
        for (size = 0; size < count; size++) {
            queryPointsArray[size] = new double[dim];
        }
        
        size = 0;
        cout << dim << endl;
        //string::size_type fred;

        while (getline(file2, line2)) {
            int i;
            
            unsigned long pos = line2.find_first_of("\t");
            line2 = line2.substr(pos+1);
            
            for (i = 0; i < dim; i++) {
                //cout << stod(line2, &fred) << endl;

                cout << stod(line2.substr(0, pos+8)) << endl;
                queryPointsArray[size][i] = stod(line2.substr(0, pos+8));
                
                pos = line2.find_first_of("\t");
                line2 = line2.substr(pos+1);
            }
            
            size++;
        }
        cout << "\n\n" << endl;

        return queryPointsArray;
    }
    else if (line.find("@metric_space cosine") != string::npos) {
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
