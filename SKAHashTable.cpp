//
//  SKAHashTable.cpp
//  ALProject
//
//  Created by Sotiris Kaniras on 19/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#include "SKAHashTable.hpp"

using namespace std;

void SKAHashTable::initHashTable(int k) {
    list = (SKAList*)malloc(sizeof(SKAList) * k);
}

void SKAHashTable::initTime() {
    long currentTime = time(NULL);
    srand((unsigned int) currentTime);
}

string SKAHashTable::generateRandomBitString() {
    int numberOfBits = 0;
    string bitString;
    
    while (numberOfBits++ < 64) {
        const int randomBit = rand() % 2; // Generate random number from 0 to 1
        bitString += to_string(randomBit);
    }
    
    return bitString;
}
