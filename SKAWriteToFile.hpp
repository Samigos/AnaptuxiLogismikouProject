#ifndef SKAWriteToFile_hpp
#define SKAWriteToFile_hpp

#include <iostream>
#include <string>
#include <fstream>

void SKACreateFile(std::ofstream&, std::string); // ofstream file and filename
void SKAWriteToFile(std::ofstream&, std::string); // ofstream file and text to be written
void SKACloseFile(std::ofstream&); // ofstream file and filename

#endif
