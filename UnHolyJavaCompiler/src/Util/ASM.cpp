#include "ASM.h"

#include <string>
#include <iostream>

std::string ASM::TokensToASM(const std::vector<Token>& tokens)
{
	std::string output;
	output.append(".386\n.model flat, stdcall\noption casemap :none\n\n");
	output.append("include /masm32/include/kernel32.inc\n");
	output.append("includelib /masm32/lib/kernel32.lib\n\n");
	output.append(".data\n");
	// variables
	output.append(".code\n");
	output.append("main:\n");
	for (int i = 0; i < tokens.size(); i++)
	{
		const Token& token = tokens.at(i);
		if (token.type == Token_T::_return)
		{
			if (i + 1 < tokens.size() && 
				tokens.at(i + 1).type == Token_T::int_lit)
			{
				if (i + 2 < tokens.size() &&
					tokens.at(i + 2).type == Token_T::semi)
				{
					output.append("invoke ExitProcess, ");
					output.append(tokens.at(i + 1).value.value() + "\n");
				}
			}
		}
	}

	output.append("end main");
	return output;
}