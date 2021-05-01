
//Created by peter on 30.04.2021.

#include <cmath>
#include "FileReader.h"
FileReader::FileReader(const std::string& fileName, char findingChar) {
    this->fileName = {fileName};
    this->findingChar = {findingChar};
    this->initializeMap();
    this->openFile();
    this->readLinesFromFile();
}
void FileReader::openFile() {
    file.open(fileName, std::ios::in);
    if(!file.good()){
        throw "File does not exist";
    }
}
void FileReader::readLinesFromFile() {
    std::string line;
    while(std::getline(file, line)){
        this->lines.push_back(line);
    }
   // std::for_each(lines.begin(), lines.end(), [](const std::string& i)->void {std::cout << i << std::endl;});

}

void FileReader::calculateCharOccurences() {

    charCoutner = 0;
    for(const auto& line: lines){
        for(auto characterFromLine: line){
            ++charCoutner;
            std::map<char, int>::iterator it = this->charAndNumberOccurences.find(characterFromLine);
            if(it != charAndNumberOccurences.end()){
                auto incrementedValue = it->second;
                incrementedValue++;
                it->second = incrementedValue;
            }
        }
    }
    charCoutner += lines.size() -1;
}

void FileReader::initializeMap() {
    for(char index = ' '; index < '~'; index++ ){
        this->charAndNumberOccurences.insert({index, 0});
    }
}

int FileReader::getCharOccurency() {
    std::map<char, int>::iterator it = this->charAndNumberOccurences.find(this->findingChar);
    if(it != charAndNumberOccurences.end()){
        return it->second;
    }
    return 0;
}

int FileReader::getMaxMinCharactersInLine(bool isMax) {
    int record = lines[0].length();
    for (const auto &line: lines){
        int numberOfCharacterCurrentLine = line.length();
        if(isMax){
            if(numberOfCharacterCurrentLine > record) record = numberOfCharacterCurrentLine;
        }
        else{
            if(numberOfCharacterCurrentLine < record) record = numberOfCharacterCurrentLine;
        }
    }
    return record;
}

void FileReader::statisticsOfFile() {
    std::cout<<"----------------- STATISTICS ----------------- "<<std::endl;
    this->calculateCharOccurences();
    std::cout<<"W pliku mamy: "<<this->charCoutner<<" znakow, uzytkownik podal znak '"<<
    this->findingChar<<"', ktory wystepuje "<< this->getCharOccurency()<<" co daje wartosc: "<< std::round((double )this->getCharOccurency()/
    this->charCoutner * 10000) / 100.0<<"%."<<std::endl;
    std::cout<<"Maksymalna ilosc linii wynosi: "<<getMaxMinCharactersInLine(true)<<std::endl;
    std::cout<<"Minimalna ilosc linii wynosi: "<<getMaxMinCharactersInLine(false)<<std::endl;
    std::cout<<"Srednia ilosc linii wynosi: "<<this->charCoutner/lines.size()<<std::endl;

}



std::string FileReader::reverseLine(std::string line) {
    if( line.length() == 0 )
        return "";

    std::string last(1,line[line.length()-1]);
    std::string reversed = reverseLine(line.substr(0,line.length()-1));
    return last+reversed;


}

std::vector<std::string> FileReader::reverseAllCharacters() {
    std::vector<std::string> result;
    for(const auto& line: lines){
        const std::string &lineResult = reverseLine(line);
        result.push_back(lineResult);
    }
    std::reverse(result.begin(), result.end());
    return result;
}

void FileReader::printLines(std::vector<std::string> lines) {

         std::for_each(lines.begin(), lines.end(), [](const std::string& i)->void {std::cout << i << std::endl;});


}

std::vector<std::string> FileReader::reverseOrderLines() {
    std::vector<std::string> result = lines;
    reverse(result.begin(), result.end());
    return result;
}

std::vector<std::string> FileReader::reverseOneLine(int number) {

    if(number < 1 || number > lines.size()) throw "Zly indeks";
    std::vector<std::string> result = lines;
    result[number-1] = reverseLine(result[number-1]);
    return result;
}

std::vector<std::string> FileReader::upperLowerCaseWord(std::string word, bool isUpperCase) {
    std::vector<std::string> result;
    std::string wordChanged = word;
    if(isUpperCase){
        std::transform(wordChanged.begin(), wordChanged.end(),wordChanged.begin(), ::toupper);
    }
    else{
        std::transform(wordChanged.begin(), wordChanged.end(),wordChanged.begin(), ::tolower);
    }
    for (auto line: lines){
        result.push_back(this-> myReplaceAll(line, word, wordChanged));

    }
    return result;
}

std::string FileReader::myReplaceAll(std::string str, const std::string& from, const std::string& to) {
    size_t start_pos = 0;
    while((start_pos = str.find(from, start_pos)) != std::string::npos) {
        str.replace(start_pos, from.length(), to);
        start_pos += to.length();
    }
    return str;
}



