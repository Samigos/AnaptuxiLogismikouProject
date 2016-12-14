#ifndef datafile_hpp
#define datafile_hpp

#include <fstream>

int countDataFileHam(std::ifstream&, std::string);
int countDataFileEu(std::ifstream&, std::string);
int getDataFileDim(std::ifstream&, std::string);
std::string readDataFileHam(std::ifstream&, std::string);
std::string readDataFileEu(std::ifstream&, std::string);

#endif
