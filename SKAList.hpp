//
//  SKAList.hpp
//  ALProject
//
//  Created by Sotiris Kaniras on 19/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#ifndef SKAList_hpp
#define SKAList_hpp

#include <iostream>
#include <string>

typedef struct List {
    List *next;
    
    std::string stringValue;
    double doubleValue;
} List;

class SKAList {
public:
    List *head;
    
    SKAList() {};
    ~SKAList() {};
    
    void add(std::string);
    void add(double);
    void print();
};

#endif /* SKAList_hpp */
