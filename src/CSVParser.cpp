#include "CSVParser.h"
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

CSVParser::CSVParser(const std::string& filename)  {
    _filename = filename;
}

CSVParser::~CSVParser() {
    // nothing to do
}

void CSVParser::parse() {
    // TODO
    std::ifstream file(_filename);
    std::string line;


    if(file.is_open()){
        std::cout << "file is open" << std::endl;
    }else {
        std::cout << "file is not open" << std::endl;
    }

    while(std::getline(file, line)) {
        std::stringstream ss(line);
        std::string field;
        std::string linestr;
        while(std::getline(ss, field, ',')) {
            linestr += field + ",";
            // _fields.push_back(field);
        } 
        // std::cout << linestr << std::endl;
        _fields.push_back(linestr);
    }

    file.close();
}

void CSVParser::print(){
    std::cout << "size : " + std::to_string(_fields.size()) << std::endl;
    // TODO
    for(auto& field : _fields) {
        std::cout << field << std::endl;
    }
    std::cout << std::endl;
}