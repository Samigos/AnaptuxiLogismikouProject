#include "SKAList.hpp"
#include <stdlib.h>

using namespace std;

void SKAList::add(std::string newValue) {
    List *temp = new List;
    temp->stringValue = newValue;
    
    if (head == NULL) {
        head = temp;
        head->next = NULL;
    }
    else {
        temp->next = head;
        head = temp;
    }
    
    length++;
}

void SKAList::add(double newValue) {
	List *temp = new List;
	temp->doubleValue = newValue;

	if (head == NULL) {
		head = temp;
		head->next = NULL;
	}
	else {
		temp->next = head;
		head = temp;
	}
    
	length++;
}

void SKAList::print() {
    while (head != NULL) {
        //cout << head->value << endl;
        head = head->next;
    }
}
