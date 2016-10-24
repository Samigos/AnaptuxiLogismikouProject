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

class SKAHashTable {
    SKAList *list;
    int numberOfBuckets;
    
    int hashFunction(std::string bitString);
public:
    SKAHashTable() {};
    ~SKAHashTable() {};
    
    void initHashTable(int);
    void addBitString(std::string);
    void print();
    
    // -----------------------------------
    // Random bit strings functions
    
    void initTime();
    std::string generateRandomBitString();
};

#endif /* SKAHashTable_hpp */
