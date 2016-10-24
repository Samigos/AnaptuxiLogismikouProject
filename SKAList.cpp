//
//  SKAList.cpp
//  ALProject
//
//  Created by Sotiris Kaniras on 19/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#include "SKAList.hpp"
#include <stdlib.h>

using namespace std;

void SKAList::add(std::string newValue) {
    List *temp = new List;
    temp->value = newValue;
    
    if (head == NULL) {
        head = temp;
        head->next = NULL;
    }
    else {
        temp->next = head;
        head = temp;
    }
}

void SKAList::print() {
    while (head != NULL) {
        cout << head->value << endl;
        head = head->next;
    }
}
