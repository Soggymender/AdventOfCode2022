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

    char buckets['z' + 1];
    int groupCount = 0;

    std::string line;
    while(std::getline(inFile, line)) {

        if (groupCount == 0 )
            memset(buckets, 0, sizeof(buckets));

        for (int i = 0; i < line.length(); i++) {
            
            char c = line.at(i);

            if (buckets[c] == groupCount) {
                buckets[c] = groupCount + 1;
            }
        }

        if (groupCount == 2) {

            for (int i = 0; i < sizeof(buckets); i++) {

                if (buckets[i] == 3) {

                    if (i >= 'a' && i <= 'z') {
                    total += i - 97 + 1;
                    } else if (i >= 'A' && i <= 'Z') {
                    total += i - 65 + 27;
                    }
                }
            }
        }

        groupCount++;
        if (groupCount == 3) 
            groupCount = 0;
    }

    std::cout << total;

    return 0;
}