#include <iostream>
#include "FileReader.h"
int main(int argc, char *argv[]) {

    auto * fileReader =  new FileReader(std::string(argv[1]), *argv[2]);
    fileReader->statisticsOfFile();
    std::cout<<std::endl;

    std::cout<<"----------------- REVERSE ALL CHARS ----------------- "<<std::endl;
    const std::vector<std::string> &result = fileReader->reverseAllCharacters();
    fileReader->printLines(result);
    std::cout<<std::endl;

    std::cout<<"----------------- REVERSE ORDER OF LINES ----------------- "<<std::endl;
    const std::vector<std::string> &result2 = fileReader->reverseOrderLines();
    fileReader->printLines(result2);
    std::cout<<std::endl;

    std::cout<<"----------------- REVERSE ALL CHARS IN LINE 2 ----------------- "<<std::endl;
    const std::vector<std::string> &result3 = fileReader->reverseOneLine(2);
    fileReader->printLines(result3);
    std::cout<<std::endl;

    std::cout<<"----------------- REVERSE ALL you INTO YOU ----------------- "<<std::endl;
    const std::vector<std::string> &result4 = fileReader->upperLowerCaseWord("you", true);
    fileReader->printLines(result4);
    std::cout<<std::endl;

    return 0;
}
