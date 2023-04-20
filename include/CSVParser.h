#ifndef CSV_PARSER_H
#define CSV_PARSER_H

#include <string>
#include <vector>

class CSVParser {
public:
    CSVParser(const std::string& filename);
    ~CSVParser();
    void parse();
    void print();

private:
    std::string _filename;
    std::vector<std::string> _fields;
};

#endif