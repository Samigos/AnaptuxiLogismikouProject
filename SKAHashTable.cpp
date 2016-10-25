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
    numberOfBuckets = pow(2, k);
    list = new SKAList[numberOfBuckets];
}

void SKAHashTable::addBitString(string bitString) {
    const int hashedIndexValue = hashFunction(bitString);
    list[hashedIndexValue].add(bitString);
}

int SKAHashTable::hashFunction(string bitString) {
    int index, sum = 0;
    
    for (index = 0; index < bitString.length(); index++) {
        const char value = bitString[index];
        sum += atoi(&value);
    }

    return sum % numberOfBuckets;
}

void SKAHashTable::print() {
    int index;
    
    for (index = 0; index < numberOfBuckets; index++) {
        cout << "Contents of bucket no " << index+1 << ":" << endl;
        list[index].print();
    }
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

