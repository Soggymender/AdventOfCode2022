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

      char buckets['z' + 1];
      memset(buckets, 0, sizeof(buckets));

      // Iterate line characters
      // 
      int c1 = 0;
      int c2 = line.length() / 2;

      int i = 0;
      
      // 1st compartment.
      for (; i < c2; i++) {
        
        char c = line.at(i);
        if (buckets[c] == 0) {
          buckets[c] = 1;
        };
      }

      // 2nd compartment.
      for (; i < line.length(); i++) {
        
        char c = line.at(i);
        if (buckets[c] != 0) {
          buckets[c] = 2;
        };
      }

      for (i = 0; i < sizeof(buckets); i++) {

        if (buckets[i] == 2) {

            if (i >= 'a' && i <= 'z') {
              total += i - 97 + 1;
            } else if (i >= 'A' && i <= 'Z') {
              total += i - 65 + 27;
            }
        }
      }

    }

    std::cout << total;

    return 0;
}