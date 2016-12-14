#include "SKAWriteToFile.hpp"

void SKACreateFile(std::ofstream& file, std::string fileName) {
    file.open(fileName);
}

void SKAWriteToFile(std::ofstream& file, std::string text) {
    file << text << "\n";
}

void SKACloseFile(std::ofstream& file) {
    file.close();
}
