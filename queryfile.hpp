/*
 * queryfile.hpp
 *
 *  Created on: Nov 22, 2016
 *      Author: Zeaniel
 */

#ifndef queryfile_hpp
#define queryfile_hpp


int countQueryFileHam(ifstream&, string);
int countQueryFileEu(ifstream&, string);
int getQueryFileDim(ifstream&, string);
string readQueryFileHam(ifstream&, string);
double readQueryFileEu(ifstream&, string, unsigned long);
int radiusQueryFile(string);

#endif


