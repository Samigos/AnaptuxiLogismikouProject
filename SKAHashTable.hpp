//
//  SKAHashTable.hpp
//  ALProject
//
//  Created by Sotiris Kaniras on 19/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#ifndef SKAHashTable_hpp
#define SKAHashTable_hpp

#include <stdio.h>
#include <time.h>
#include <string>
#include <stdlib.h>
#include "SKAList.hpp"

void initTime();
std::string generateRandomBitString();

class SKAHashTable {
    SKAList list;
    
public:
    SKAHashTable(int k = 4, int L = 5);
    ~SKAHashTable() {};
};

#endif /* SKAHashTable_hpp */
