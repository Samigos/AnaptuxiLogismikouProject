#ifndef datafile_hpp
#define datafile_hpp



int countDataFileHam(ifstream&, string);
int countDataFileEu(ifstream&, string);
int getDataFileDim(ifstream&, string);
string readDataFileHam(ifstream&, string);
string readDataFileEu(ifstream&, string);
double ConvertFileEu(string, unsigned);

#endif
