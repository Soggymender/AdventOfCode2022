#include <iostream>
#include <string>
#include <sstream>
#include <ios>
#include <fstream>

int main()
{
  std::string filename = "input.txt";

//  std::ostringstream dosString(std::ios::out | std::ios::binary);
  std::ifstream inFile(filename.c_str());

  int total = 0;
  int max = 0;

  std::string line;
  while(std::getline(inFile, line)) {

    if (line.length() == 0) {

      if (total > max) {
        max = total;
      }

      total = 0;
      continue;
    }

    int num = stoi(line);

    total += num;
  }

  std::cout << max;

  return 0;
}