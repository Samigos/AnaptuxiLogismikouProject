//
//  Euclidian.cpp
//  ALProject
//
//  Created by Sotiris Kaniras on 31/10/16.
//  Copyright © 2016 com.me. All rights reserved.
//

#include <iostream>
#include <math.h>

using namespace std;

double distanceCalculate(double x1, double y1, double x2, double y2, int radius) {
    double x = x1 - x2; //calculating number to square in next step
    double y = y1 - y2;
    double dist;
    
	int count = 0;
    
    dist = pow(x, 2) + pow(y, 2); //calculating Euclidean distance
    dist = sqrt(dist);

    if (dist < radius) {
        dist = pow(x, 2) + pow(y, 2); //calculating Euclidean distance
        dist = sqrt(dist);
        
        count++;
	}
             
    return dist;
}
