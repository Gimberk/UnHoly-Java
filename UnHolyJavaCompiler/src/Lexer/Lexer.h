#pragma once

#include <vector>

#include "Token.h"

class Lexer
{
public:
	static std::vector<Token> GenerateTokens(const std::string input);
};