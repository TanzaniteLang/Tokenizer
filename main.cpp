#include <cstdio>
#include <iostream>
#include <string>
#include <vector>

#include "src/utils.hpp"

int main() {
    std::string file = Tanzanite::Tokenizer::Utils::readFile("./main.tzn");

    std::vector<Tanzanite::Tokenizer::TokenInfo> tokens = Tanzanite::Tokenizer::tokenizeStr(file);

    for (auto token : tokens) {
        printf("%s, %d [%d, %d]\n", token.text.c_str(), token.line, token.pos[0], token.pos[1]);
    }

    return 0;
}
