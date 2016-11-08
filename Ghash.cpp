#include <iostream>
#include <time.h>
#include <string>
#include <stdlib.h>
#include <math.h>
#include "Ghash.hpp"



int SKAHashTable::H(int metricSpaceId, int fileLines) {
	if (metricSpaceId == HAMMING) {
		const unsigned int h = (rand() % fileLines) + 1;
		return h;
	}

	return -1;
}

int SKAHashTable::H(int metricSpaceId) {
	if (metricSpaceId == EUCLIDIAN) {
		double x = ((rand() % 99999) + 1) / 100000;
		double y = ((rand() % 99999) + 1) / 100000;

		// -------------------------------------

		while (findDuplicateCoordinates(x, y)) {
			x = ((rand() % 99999) + 1) / 100000;
			y = ((rand() % 99999) + 1) / 100000;
		}

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

int** SKAHashTable::G(int k, int L, int fileLines, int metricSpaceId) {
	int array[L][2 ^ k];
	int i, j;

	for (i = 0; i < L; i++) {
		for (j = 0; j < (2 ^ k); j++) {
			array[i][j] = H(metricSpaceId, fileLines);
		}
	}
	return array;
}

int** SKAHashTable::G(int k, int L, int metricSpaceId) {
	int array[L][2 ^ k];
	int i, j;

	for (i = 0; i < L; i++) {
		for (j = 0; j < (2 ^ k); j++) {
			array[i][j] = H(metricSpaceId);
		}
	}
	return array;
}
