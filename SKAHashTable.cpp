//
//  SKAHashTable.cpp
//  ALProject
//
//  Created by Sotiris Kaniras on 19/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#include "SKAHashTable.hpp"

using namespace std;

void SKAHashTable::init(int k) {
    numberOfBuckets = 2^k;
    list = new SKAList[numberOfBuckets];
    
    xList = *new SKAList;
    yList = *new SKAList;
}

int SKAHashTable::H(int metricSpaceId, int fileLines) {
    if (metricSpaceId == HAMMING) {
        const unsigned int h = (rand() % fileLines) + 1;
        return h;
    }
    
    return -1;
}

int SKAHashTable::H(int metricSpaceId) {
    if (metricSpaceId == EUCLIDIAN) {
        double x = ((rand() % 99999) + 1) / 100000;
        double y = ((rand() % 99999) + 1) / 100000;
        
        // -------------------------------------
        
        while (findDuplicateCoordinates(x, y)) {
            x = ((rand() % 99999) + 1) / 100000;
            y = ((rand() % 99999) + 1) / 100000;
        }
        
        // -------------------------------------
        
        const double z = ((rand() % 99999) + 1) / 100000;
        const double p = x / z;

        const int w = 4;
        const int t = ((rand() % (w * 10000))) / 10000; // 0 - 3.999
        const double n = sqrt((x * x) + (y * y));
        
        // -------------------------------------
        
        const int h = ((p * n) + t) / w;
        return h;
    }
    else if (metricSpaceId == COSINE) {
        
    }
}

void SKAHashTable::G(int k, int L, int fileLines, int metricSpaceId) {
    int array[2^k][L];
    int i, j;
    
    for (i = 0; i < L; i++) {
        for (j = 0; j < (2^k); j++) {
            array[i][j] = H(metricSpaceId, fileLines);
        }
    }
}

void SKAHashTable::G(int k, int L, int metricSpaceId) {
    int array[2^k][L];
    int i, j;
    
    for (i = 0; i < L; i++) {
        for (j = 0; j < (2^k); j++) {
            array[i][j] = H(metricSpaceId);
        }
    }
}

void SKAHashTable::search() {
    
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

bool SKAHashTable::findDuplicateCoordinates(double coordinateXValue, double coordinateYValue) {
    while (xList.head != NULL && yList.head != NULL) {
        if (xList.head->floatValue == coordinateXValue && yList.head->floatValue == coordinateYValue) {
            return true;
        }
        
        xList.head = xList.head->next;
        yList.head = yList.head->next;
    }
    
    return false;
}

void SKAHashTable::print() {
    int index;
    
    for (index = 0; index < numberOfBuckets; index++) {
        cout << "Contents of bucket no " << index+1 << ":" << endl;
        list[index].print();
    }
}
