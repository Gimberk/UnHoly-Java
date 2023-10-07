#include "Lexer/Lexer.h"

int main()
{
    std::string input = "return 69;";
    std::vector<Token> tokens = Lexer::GenerateTokens(input);
    return EXIT_SUCCESS;
}