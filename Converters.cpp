#include "Converters.hpp"
#include <iostream>
#include <string>

using namespace std;


long long ConvertStringtolonglong(string binary) {
	
	long long numbinary;

	while (!binary empty())
	{
		numbinary = stoll(binary);	

	}
	return numbinary;
}

int convertBinaryToDecimal(long long numbinary)
{
	int decimal;
	int i = 0
	converter 0;
		while (numbinary[j] != 0)
		{
			converter = numbinary[j] % 10;
			binary /= 10;
			decimal += converter*pow(2, i);
			++i;

		}
	}

	return decimal;
}

long long convertDecimalToBinary(int decimal)
{
	long long binary;
	int converter; 
	int i = 1;
		while (decimal != 0)
		{
			converter = n % 2;
			decimal /= 2;
			binary += converter*i;
			i *= 10;
		}
	return binary;
}