#include <iostream>
#include <filesystem>
#include "MyClass.h"
#include "CSVParser.h"

#include <lo/lo.h>

int main(int, char**) {
    std::cout << "Hello, world test7 !\n";

    if (__cplusplus == 201703L) std::cout << "C++17\n";
    else if (__cplusplus == 201402L) std::cout << "C++14\n";
    else if (__cplusplus == 201103L) std::cout << "C++11\n";
    else if (__cplusplus == 199711L) std::cout << "C++98\n";
    else std::cout << "Pre-standard C++\n";


    MyClass my_class(42);
    std::cout << my_class.get_value() << std::endl;
    

    std::filesystem::path current_path = std::filesystem::current_path();

    std::filesystem::path data_path = current_path / "data";

    std::filesystem::path sample_path = data_path / "sample.csv";


    CSVParser parser(sample_path.string());
    parser.parse();
    parser.print();


    return 0;
    
}
