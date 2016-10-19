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

void shit() {
    ifstream file("DataEuclidean.csv"); // eisodos tou arxeiou
    string line;
    
    getline(file, line);
    
    if (line.find("@metric_space hamming") != std::string::npos) {
        while (getline(file, line)) {
            unsigned long pos = line.find_first_of("\t");
            line = line.substr(pos+1);
            
            cout << line << endl;
        }
    }
    else if ((line.find("@metric_space euclidean") != std::string::npos) ||
             (line.find("@metric_space cosine") != std::string::npos)) {
        
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
}

using namespace std;

int main(int argc, const char * argv[]) {
    int k = 4, L = 5, index;
    string d, q, o;
    shit();
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
        
    return 0;
}
