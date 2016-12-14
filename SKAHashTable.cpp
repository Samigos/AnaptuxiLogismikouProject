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
	return (long)numberValue % numberOfBuckets;
}

void SKAHashTable::print() {
    int index;
    
    for (index = 0; index < numberOfBuckets; index++) {
        cout << "Contents of bucket no " << index+1 << ":" << endl;
        list[index].print();
    }
}

std::string SKAHashTable::getHeads(int index) {
	string headOfList;
	headOfList = list[index].head->stringValue;

    return headOfList;
}

std::string* SKAHashTable::getBody(int i){
    const int length = list[i].length;
    int j = 0;
	string* bodyarray = new string[length];
    
    while(list[i].head != NULL){
        bodyarray[j] = list[i].head->stringValue;
        list[i].head = list[i].head->next;
        
        j++;
    }

	return bodyarray;
}
