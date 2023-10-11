#include "Lexer/Lexer.h"
#include "Util/ASM.h"

#include <fstream>
#include <sstream>

int main()
{
    std::string content;
    {
        std::stringstream contents_stream;
        std::fstream input("../UnHolyJavaCompiler/content/Text.uhj", std::ios::in);
        contents_stream << input.rdbuf();
        content = contents_stream.str();
    }

    std::vector<Token> tokens = Lexer::GenerateTokens(content);
    {
        std::fstream file("out.asm", std::ios::out);
        file << ASM::TokensToASM(tokens);
    }

    return EXIT_SUCCESS;
}