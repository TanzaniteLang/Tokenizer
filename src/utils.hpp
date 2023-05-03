#ifndef TANZANITE_TK_UTILS
#define TANZANITE_TK_UTILS

#include <string>
#include <vector>

namespace Tanzanite::Tokenizer::Utils
{
    std::string readFile(std::string name);
}

namespace Tanzanite::Tokenizer {
    typedef struct {
        std::string text;
        int line;
        int pos[2];
    } TokenInfo;

    std::vector<Tanzanite::Tokenizer::TokenInfo> tokenizeStr(std::string str);
}

#endif
