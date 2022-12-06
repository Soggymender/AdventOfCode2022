#include <iostream>
#include <string>
#include <sstream>
#include <ios>
#include <fstream>
#include <cstring>
#include <regex>

int main()
{
    std::string filename = "input.txt";

//    std::ostringstream dosString(std::ios::out | std::ios::binary);
    std::ifstream inFile(filename.c_str());

    int total = 0;
    std::regex e("[-,]+");

    std::string line;
    while(std::getline(inFile, line)) {
    
        std::regex_token_iterator<std::string::iterator> i(line.begin(), line.end(), e, -1);
        std::regex_token_iterator<std::string::iterator> end;
        
        int al = std::stoi((std::string)*i++);
        int ar = std::stoi((std::string)*i++);
        int bl = std::stoi((std::string)*i++);
        int br = std::stoi((std::string)*i++);

        if (al >= bl && ar <= br)
            total++;

        else if (bl >= al && br <= ar)
            total++;

//        while (i != end) {
 //           std::cout << " [" << *i++ << "]";
   //     }
    }

    std::cout << total;

    return 0;
}