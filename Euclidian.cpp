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

double distanceCalculate(double x1[][][], double y1[][], int q, int w , int e, int r, int t) {
    double x = x1[q][w][0];
    double y = y1[r][0];
    double dist;
    int i;

    for(i = 1; i < e; i++){

    	x = x - x1[q][w][i];
    }

    for(i = 1; i < t; i++){

    	y = y - y1[r][i];
    }

    dist = pow(x, 2) + pow(y, 2); //calculating Euclidean distance
    dist = sqrt(dist);


    return dist;
}

double distanceCalculate(double x1[][], double y1[][], int q, int w , int e) {
    double x = x1[q][0];
    double y = y1[w][0];
    double dist;
    int i;

    for(i = 1; i < e; i++){

    	x = x - x1[q][i];
    }
    
    for(i = 1; i < e; i++){

    	y = y - y1[w][i];
    }
    
    dist = pow(x, 2) + pow(y, 2); //calculating Euclidean distance
    dist = sqrt(dist);

             
    return dist;
}
