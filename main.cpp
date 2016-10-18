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

using namespace std;

int main(int argc, const char * argv[]) {
    int k = 4, L = 5;
    string d, o, q;
    
    int index;
    
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
    
    const string bitString = generateRandomBitString();
    cout << bitString << endl;
        
    return 0;
}
