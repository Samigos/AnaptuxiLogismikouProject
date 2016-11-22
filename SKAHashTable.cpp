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



void SKAHashTable::addBitString(string bitString) {
    const int hashedIndexValue = hashFunction(bitString);
    list[hashedIndexValue].add(bitString);
}

void SKAHashTable::addDouble(double number) {
	const int hashedIndexValue = hashFunction(number);
	list[hashedIndexValue].add(number);
}

int SKAHashTable::hashFunction(string bitString) {
    int index, sum = 0;
    
    for (index = 0; index < bitString.length(); index++) {
        const char value = bitString[index];
        sum += atoi(&value);
    }

    return sum % numberOfBuckets;
}

int SKAHashTable::hashFunction(double numberValue) {
	return numberValue % numberOfBuckets;
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

std::string SKAHashTable::getHeads(int i) {

	//int i;
	string headsarray;
	//for (i = 0; i < numberOfBuckets; i++) {

		headsarray = list[i]->head->stringValue;
	//}
	return headsarray;
}

std::string* SKAHashTable::getBody(int i){

	const int length = list[i].length;
	string* bodyarray = new string[length];
	int j = 0;
		while(list[i]->head != NULL){

			bodyarray[j] = list[i]->head->stringValue;
			list[i]->head = list[i]->head->next;
			j++;
		}

	return bodyarray;

}
