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
    int length;
    
    SKAList() {};
    ~SKAList() {};
    
    void add(std::string);
    void add(double);
    void print();
};

#endif /* SKAList_hpp */
