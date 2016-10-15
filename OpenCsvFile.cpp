    #include <iostream>
    #include <sstream>
    #include <string>
    #include <fstream>
       
	std::ifstream file("path"); 
	file.ignore ( std::numeric_limits<std::streamsize>::max(), '\n' );
        std::string line = "";
	while (getline(file, line))
		{
		stringstream strstr(line);
		int pos = line.find_first_of("");
		line= line.substr(pos+1);
		cout << line << endl;
		}
