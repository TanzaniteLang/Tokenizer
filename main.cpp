#include <iostream>
#include <string>

#include "src/utils.hpp"

int main() {
    std::string file = Tanzanite::Tokenizer::Utils::readFile("./main.tzn");
    std::cout << file << std::endl;

    return 0;
}
