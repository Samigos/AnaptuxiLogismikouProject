#include <iostream>
#include <string>

int hamming_distance(std::string& fs, std::string& ss){
    int hm_distance = 0;
    
    if((fs.length() == ss.length())){
      
      for(int i = 0; i < fs.length(); i++){
        if(!(fs[i] == ss[i])){
          hm_distance++;
        }
      }
      
    }else{
      hm_distance = -1;  
    }
    return hm_distance;
}

int main (){
  
  std::string s1, s2;
  int hm_distance;
  
  while(true){
    // prompt
    std::cout << "Input First String: ";
    getline(std::cin, s1);
    std::cout << "Input Second String: ";
    getline(std::cin, s2);
    
    hm_distance = hamming_distance(s1, s2); // get the value
    
    // check and display
    if(hm_distance >= 0){
      std::cout << "\nHamming Distance"
      << " for those strings: "
      << hm_distance << "\n\n";
    }else{
      std::cout << "String are not equal in size!\n\n";
    }
  }
  
  return 0;
}
