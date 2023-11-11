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

    Lexer lexer;

    std::vector<Token> tokens = lexer.GenerateTokens(content);
    {
        std::fstream file("out.asm", std::ios::out);
        file << ASM::TokensToASM(tokens);
    }

    system("ml /c /Zd /coff out.asm");
    system("Link /SUBSYSTEM:CONSOLE out.obj");

    return EXIT_SUCCESS;
}