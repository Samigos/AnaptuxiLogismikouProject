//
//  main.cpp
//  ALProject
//
//  Created by Sotiris Kaniras on 14/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

void createRandomBitString();

int main(int argc, const char * argv[]) {
    int k = 4, L = 5;
    string d;
    
    int index;
    
    for (index = 0; index < argc; index++) {
        if (strcmp(argv[index], "-k") == 0) {
            k = atoi(argv[index+1]);
        }
        else if (strcmp(argv[index], "-L") == 0) {
            L = atoi(argv[index+1]);
        }
        else if (strcmp(argv[index], "-d") == 0) {
            d = string(argv[index+1]);
        }
    }
    
    cout << k << ", " << L << endl;

    return 0;
}
