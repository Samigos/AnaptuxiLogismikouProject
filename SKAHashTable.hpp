//
//  SKAHashTable.hpp
//  ALProject
//
//  Created by Sotiris Kaniras on 19/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#ifndef SKAHashTable_hpp
#define SKAHashTable_hpp

#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include "SKAList.hpp"

#define HAMMING 1
#define EUCLIDIAN 2
#define COSINE 3

class SKAHashTable {
    SKAList *list;
    SKAList xList, yList;
    
    int numberOfBuckets;
    
    int hashFunction(std::string);
public:
    SKAHashTable() {};
    ~SKAHashTable() {};
    
    void init(int);
    
    int H(int, int);
    int H(int);
    
    void G(int, int, int, int);
    void G(int, int, int);
    
    void search();
    
    void addBitString(std::string);
    bool findDuplicateCoordinates(double, double);
    
    void print();
};

#endif /* SKAHashTable_hpp */
