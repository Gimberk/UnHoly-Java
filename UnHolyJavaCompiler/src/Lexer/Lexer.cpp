#include "Lexer.h"

Token_T GetTokenType(std::string word)
{
	if (word == "return") return Token_T::_return;
	return Token_T::none;
}

void Lexer::FormTokens() {
	validTokens[Token_T::_return] = { .type = Token_T::_return, .requisites = {Token_T::int_lit} };
}

std::vector<Token> Lexer::GenerateTokens(const std::string input)
{
	std::vector<Token> tokens;
	std::string buffer;
	for (int i = 0; i < input.size(); i++)
	{
		buffer.clear();
		char c = input.at(i);
		if (std::isalpha(c))
		{
			buffer.push_back(c);
			i++;
			while (std::isalnum(input.at(i)))
			{
				buffer.push_back(input.at(i));
				i++;
			}
			i--;
			
			Token_T type = GetTokenType(buffer);
			Token token = validTokens[type];
			if (type != Token_T::none) tokens.push_back(token);
			else
			{
				std::cerr << "SATIN IS ANGRY!!!" << '\n';
				exit(EXIT_FAILURE);
			}
		}
		else if (std::isdigit(c))
		{
			buffer.push_back(c);
			i++;
			while (std::isdigit(input.at(i)) || input.at(i) == '.')
			{
				buffer.push_back(input.at(i));
				i++;
			}
			i--;
			Token token = { .type = Token_T::int_lit, .value = buffer };
			tokens.push_back(token);
		}
		else if (c == ';')
		{
			tokens.push_back({ .type = Token_T::semi });
		}
		else if (std::isspace(c)) continue;
		else
		{
			std::cerr << "SATIN IS ANGRY!!! 2" << '\n';
			exit(EXIT_FAILURE);
		}
	}
	return tokens;
}