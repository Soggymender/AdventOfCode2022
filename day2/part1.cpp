#include <iostream>
#include <string>
#include <sstream>
#include <ios>
#include <fstream>

int getShapeScore(char shape) {

  if (shape == 'A' || shape == 'X')
    return 1;

  if (shape == 'B' || shape == 'Y')
    return 2;

  if (shape == 'C' || shape == 'Z')
    return 3;

  return 0;
}

int main()
{
    std::string filename = "input.txt";

//    std::ostringstream dosString(std::ios::out | std::ios::binary);
    std::ifstream inFile(filename.c_str());

    int aScore = 0;
    int bScore = 0;

    std::string line;
    while(std::getline(inFile, line)) {

        char aShape = line.at(0);
        char bShape = line.at(2);

        bool win = false;
        bool lose = false;
        bool tie = false;

        if (bShape - aShape == 23) {
          tie = true;
        } else if (aShape == 'A') {

          if (bShape == 'Y') {
            win = true;
          } else if (bShape == 'Z') {
            lose = true;
          }

        } else if (aShape == 'B') {
          if (bShape == 'X') {
             lose = true;
          } else if (bShape == 'Z') {
            win = true;
          }

        } else if (aShape == 'C') {
          if (bShape == 'X') {
             win = true;
          } else if (bShape == 'Y') {
            lose = true;
          }
        }

      //  if (!tie) {
          aScore += getShapeScore(aShape);
          bScore += getShapeScore(bShape);
      //  }

        if (win) {
          aScore += 0;
          bScore += 6;

        } else if (lose) {
          aScore += 6;
          bScore += 0;

        } else if (tie) {
          aScore += 3;
          bScore += 3;
        }

    }

    std::cout << bScore;

    return 0;
}