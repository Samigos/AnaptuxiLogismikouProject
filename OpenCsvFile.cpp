    #include <iostream>
    #include <sstream>
    #include <string>
    #include <fstream>

        ifstream file("path"); // tha valoume edw to path pou theloume
        file.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
        string line = "";
        while (getline(file, line))
	  {
            stringstream strstr(line);
            int pos = line.find_first_of("")
            line= line.substr(pos+1)
          }
    
