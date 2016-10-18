//
//  SKAList.hpp
//  ALProject
//
//  Created by Sotiris Kaniras on 19/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#ifndef SKAList_hpp
#define SKAList_hpp

#include <stdio.h>
#include <string>

typedef struct List {
    List *next;
    std::string value;
} List;

class SKAList {
    List *head, *list;
    
public:
    SKAList();
    ~SKAList() {};
    
    void add(std::string);
    void print();
};

#endif /* SKAList_hpp */
