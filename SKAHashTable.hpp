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
	int hashFunction(double);
public:
    SKAHashTable() {};
    ~SKAHashTable() {};
    
    void init(int);
    
    std::string getHeads(int);
	std::string* getBody(int);
    void addBitString(std::string);
	void addDouble(double);
    
    void print();
};

#endif /* SKAHashTable_hpp */
