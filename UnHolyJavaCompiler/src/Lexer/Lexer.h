#pragma once

#include <map>

#include "Token.h"

class Lexer
{
private:
	void FormTokens();

public:
	std::map<Token_T, Token> validTokens;

	std::vector<Token> GenerateTokens(const std::string input);

	Lexer() {
		FormTokens();
	}
};