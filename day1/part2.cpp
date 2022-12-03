#include <iostream>
#include <string>
#include <sstream>
#include <ios>
#include <fstream>

void replaceMax(int num, int max[]) {

    int lowestIdx = 0;
    for (int i = 1; i < 3; i++) {
        if (max[i] < max[lowestIdx]) {
            lowestIdx = i;
        }
    }

    if (num > max[lowestIdx]) {
        max[lowestIdx] = num;
    }
}

int accumulate(int max[]) {

    int total = 0;

    for (int i = 0; i < 3; i++) {
        total += max[i];    
    }

    return total;
}

int main()
{
    std::string filename = "input.txt";

//    std::ostringstream dosString(std::ios::out | std::ios::binary);
    std::ifstream inFile(filename.c_str());

    int total = 0;
    int max[3] = {0, 0, 0};

    std::string line;
    while(std::getline(inFile, line)) {

        if (line.length() == 0) {

            replaceMax(total, max);
            total = 0;
            continue;
        }

        int num = stoi(line);

        total += num;
    }

    std::cout << accumulate(max);

    return 0;
}