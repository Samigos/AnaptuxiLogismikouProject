#include <iostream>
#include <string>

using namespace std;
int hamming_distance(int, int, int);

int hamming_distance(int num1, int num2, int radius) {
	int result = 0;

		if (num1 > num2) {

			result = num1 - num2;
		}
		else {

			result = num2 - num1;
		}

		if (radius > result) {

			return result;

		}
		else {
			return -1;
		}
	}

	