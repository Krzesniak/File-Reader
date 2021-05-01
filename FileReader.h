//
// Created by peter on 30.04.2021.
//

#ifndef FILE_READER_FILEREADER_H
#define FILE_READER_FILEREADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>

class FileReader {

private:
    std::vector<std::string> lines;
    std::map<char, int> charAndNumberOccurences;
    std::string fileName;
    char findingChar;
    std::fstream file;
    int charCoutner;
    void initializeMap();
public:
    FileReader(const std::string& fileName, char findingChar);
    void openFile();
    void readLinesFromFile();
    void calculateCharOccurences();
    int getCharOccurency();
    int getMaxMinCharactersInLine(bool isMax);
    std::vector<std::string> reverseAllCharacters();
    void statisticsOfFile();
    std::string reverseLine(std::string line);
    void printLines(std::vector<std::string> lines);
    std::vector<std::string> reverseOrderLines();
    std::vector<std::string> reverseOneLine(int number);
    std::vector<std::string> upperLowerCaseWord(std::string word, bool isUpperCase);
    std::string myReplaceAll(std::string str, const std::string& from,  const std::string& to);


};


#endif //FILE_READER_FILEREADER_H
