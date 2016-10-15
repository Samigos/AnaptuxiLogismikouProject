//
//  SKARandomBitString.cpp
//  ALProject
//
//  Created by Sotiris Kaniras on 15/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#include "SKARandomBitString.hpp"
#include <iostream>

using namespace std;

void initTime() {
    long currentTime = time(NULL);
    srand((unsigned int) currentTime);
}

string generateRandomBitString() {
    int numberOfBits = 0;
    string bitString;
    
    while (numberOfBits++ < 64) {
        const int randomBit = rand() % 2;
        bitString += to_string(randomBit);
    }
    
    return bitString;
}
