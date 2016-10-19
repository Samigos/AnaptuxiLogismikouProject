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

class SKAHashTable {
    SKAList *list;
    
public:
    SKAHashTable();
    ~SKAHashTable() {};
    
    void initHashTable(int);
    
    // -----------------------------------
    // Random bit strings functions
    
    void initTime();
    std::string generateRandomBitString();
};

#endif /* SKAHashTable_hpp */
