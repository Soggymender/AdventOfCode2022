#include <iostream>
#include <string>
#include <sstream>
#include <ios>
#include <fstream>
#include <cstring>

int main()
{
    std::string filename = "input.txt";

//    std::ostringstream dosString(std::ios::out | std::ios::binary);
    std::ifstream inFile(filename.c_str());

    int total = 0;

    std::string line;
    while(std::getline(inFile, line)) {

    }

    std::cout << total;

    return 0;
}