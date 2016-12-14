#include <iostream>
#include <string>
#include "Hamming.hpp"

using namespace std;

int hamming_distance(string fs, string ss){
    int hm_distance = 0;

    if (fs.length() == ss.length()) {
        for (int i = 0; i < fs.length(); i++) {
            if (!(fs[i] == ss[i])) {
                hm_distance++;
            }
        }
    }
    
    return hm_distance;
}
	
