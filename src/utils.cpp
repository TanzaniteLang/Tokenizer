#include <cctype>
#include <string>
#include <vector>
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

std::vector<Tanzanite::Tokenizer::TokenInfo> Tanzanite::Tokenizer::tokenizeStr(std::string str) {
    std::vector<Tanzanite::Tokenizer::TokenInfo> tokens;

    std::string tmp;

    int line = 0;
    int start = 0;

    char startedWith = 0;

    for (int i = 0; i < str.length(); i++) {
        if (startedWith && str[i] == '\\') {
            if (str[i + 1] == startedWith) {
                tmp += str[i];
                i++;
                tmp += str[i];
                continue;
            }
        }
        if (str[i] == '"' || str[i] == '\'') {
            if (!startedWith)
                startedWith = str[i];
            else if (startedWith == str[i]) {
                startedWith = 0;
            }
        }
        if (isspace(str[i]) && !startedWith) {
            if (tmp.length() > 0) { 
                Tanzanite::Tokenizer::TokenInfo info = {};
                info.text = tmp;
                info.line = line;
                info.pos[0] = start;
                info.pos[1] = start + tmp.length();
                tokens.push_back(info);
                tmp = "";
            }
        } else {
            tmp += str[i];
            if (!isspace(str[i])) {
                start++;
            }
        }

        if (str[i] == '\n') {
            line++;
            start = 0;
        }
    }

    return tokens;
}
