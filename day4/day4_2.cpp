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

    std::ifstream inFile(filename.c_str());

    int total = 0;

    std::regex e("[-,]+");

    std::string line;
    while(std::getline(inFile, line)) {

        // New to me.
        std::regex_token_iterator<std::string::iterator> i(line.begin(), line.end(), e, -1);
        std::regex_token_iterator<std::string::iterator> end;
        
        int al = std::stoi((std::string)*i++);
        int ar = std::stoi((std::string)*i++);
        int bl = std::stoi((std::string)*i++);
        int br = std::stoi((std::string)*i++);

        // Basically AABB overlap test just on X.
        if(al <= bl + (br - bl) &&
            al + (ar - al) >= bl)
            total++;
    }

    std::cout << total;

    return 0;
}