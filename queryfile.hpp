#ifndef queryfile_hpp
#define queryfile_hpp

#include <iostream>
#include <fstream>

int countQueryFileHam(std::ifstream&, std::string);
int countQueryFileEu(std::ifstream&, std::string);
int getQueryFileDim(std::ifstream&, std::string);
std::string readQueryFileHam(std::ifstream&, std::string);
double readQueryFileEu(std::ifstream&, std::string, unsigned long);
int radiusQueryFile(std::string);

#endif


