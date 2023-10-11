#pragma once

#include "../Lexer/Token.h"
#include <vector>

class ASM
{
public:
	static std::string TokensToASM(const std::vector<Token>& tokens);
};

