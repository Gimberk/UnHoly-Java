#include "Lexer.h"

std::vector<Token> Lexer::GenerateTokens(const std::string input)
{
	std::vector<Token> tokens;
	std::string buffer;
	for (int i = 0; i < input.size(); i++)
	{
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
			if (buffer == "return")
			{
				tokens.push_back({ .type = Token_T::_return });
				buffer.clear();
			}
			else
			{
				std::cout << buffer << std::endl;
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
			tokens.push_back({ .type = Token_T::int_lit, .value = buffer });
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