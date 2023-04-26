#include <string>
#include <iostream>
#include <fstream>

#include "utils.hpp"

std::string Tanzanite::Tokenizer::Utils::readFile(std::string name) {
    std::ifstream file(name);

    std::string out;
    std::string line;

    while (std::getline(file, line)) {
        out += line + "\n";
    }

    file.close();

    return out;
}
