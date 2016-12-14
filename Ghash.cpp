#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include "Ghash.hpp"

#define HAMMING 1
#define EUCLIDIAN 2
#define COSINE 3

using namespace std;

bool valueExists(int valueToSearch, int** arrayToSearch, int k, int L) {
    int i, j;
    
    for (i = 0; i < L; i++) {
        for (j = 0; j < (2 ^ k); j++) {
            if (arrayToSearch[i][j] == valueToSearch) {
                return true;
            }
        }
    }
    
    return false;
}

int H(int metricSpaceId, int fileLines) {
	if (metricSpaceId == HAMMING) {
		const unsigned int h = (rand() % fileLines) + 1;
		return h;
	}

	return -1;
}

int H(int metricSpaceId) {
	if (metricSpaceId == EUCLIDIAN) {
		double x = ((rand() % 99999) + 1) / 100000;
		double y = ((rand() % 99999) + 1) / 100000;

		// -------------------------------------
        
        x = ((rand() % 99999) + 1) / 100000;
        y = ((rand() % 99999) + 1) / 100000;
        
		// -------------------------------------

		const double z = ((rand() % 99999) + 1) / 100000;
		const double p = x / z;

		const int w = 4;
		const int t = ((rand() % (w * 10000))) / 10000; // 0 - 3.999
		const double n = sqrt((x * x) + (y * y));

		// -------------------------------------

		const int h = ((p * n) + t) / w;
		return h;
	}
	else if (metricSpaceId == COSINE) {

    }
    
	return 0;
}

int** G(int k, int L, int fileLines, int metricSpaceId) {
    int i, j;
    int** array = new int*[L];
    
    for (i = 0; i < (2 ^ k); i++)
        array[i] = new int[(2 ^ k)];
    
    // ---------------------------

	for (i = 0; i < L; i++) {
        for (j = 0; j < (2 ^ k); j++) {
            int value = H(metricSpaceId, fileLines);
            
            while (valueExists(value, array, k, L)) {
                value = H(metricSpaceId, fileLines);
            }
            
			array[i][j] = value;
		}
	}
    
	return array;
}

int** G(int k, int L, int metricSpaceId) {
    int i, j;
    int** array = new int*[L];
    
    for (i = 0; i < (2 ^ k); i++)
        array[i] = new int[(2 ^ k)];
    
    // ---------------------------
    
	for (i = 0; i < L; i++) {
		for (j = 0; j < (2 ^ k); j++) {
            int value = H(metricSpaceId);
            
            while (valueExists(value, array, k, L)) {
                value = H(metricSpaceId);
            }
            
            array[i][j] = value;
		}
	}
    
	return array;
}
