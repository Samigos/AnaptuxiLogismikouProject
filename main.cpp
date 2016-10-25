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
#include "SKAHashTable.hpp"
#include <sstream>
#include <fstream>

using namespace std;

int openFile(string, bool, string*);

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
    
    SKAHashTable *ht = new SKAHashTable[L];
    
    for (index = 0; index < L; index++) {
        ht[index].initHashTable(k);
    }
    
    int arraySize = openFile(d, true, NULL);
    
    string *dataArray = new string[arraySize];
    openFile(d, false, dataArray);
    
    int i;
    for (i = 0; i < arraySize; i++) {
        cout << dataArray[i] << endl;
    }
    
    return 0;
}

int openFile(string filePath, bool calledForCount, string *dataArray) {
    ifstream file(filePath);
    string line;
    
    getline(file, line);
    
    if (line.find("@metric_space hamming") != string::npos) {
        if (calledForCount) {
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
    else if ((line.find("@metric_space euclidean") != string::npos) ||
             (line.find("@metric_space cosine") != string::npos)) {
        
        string currentLine = line;
        getline(file, line);
        
        while (getline(file, line)) {
            unsigned long pos = line.find_first_of("\t");
            line = line.substr(pos+1);
            
            cout << line << endl;
        }
    }
    else {
        
    }
    return 0;
}
