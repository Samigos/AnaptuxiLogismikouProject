//
//  SKAHashTable.cpp
//  ALProject
//
//  Created by Sotiris Kaniras on 19/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#include "SKAHashTable.hpp"
#include <iostream>

using namespace std;

SKAHashTable::SKAHashTable() {
    
}

void SKAHashTable::initHashTable(int k) {
    
}

void SKAHashTable::initTime() {
    long currentTime = time(NULL);
    srand((unsigned int) currentTime);
}

string SKAHashTable::generateRandomBitString() {
    int numberOfBits = 0;
    string bitString;
    
    while (numberOfBits++ < 64) {
        const int randomBit = rand() % 2;
        bitString += to_string(randomBit);
    }
    
    return bitString;
}
