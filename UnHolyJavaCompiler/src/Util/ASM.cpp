#include "ASM.h"


std::string ASM::TokensToASM(const std::vector<Token>& tokens)
{
	std::string output;
	output.append("global _start\n_start:\n");
	for (int i = 0; i < tokens.size(); i++)
	{
		const Token& token = tokens.at(i);
		if (token.type == Token_T::_return)
		{
			if (static_cast<unsigned long long>(i) + 1 < tokens.size() && 
				tokens.at(static_cast<std::vector<Token, std::allocator<Token>>::size_type>(i) + 1).type == Token_T::int_lit)
			{
				if (static_cast<unsigned long long>(i) + 2 < tokens.size() &&
					tokens.at(static_cast<std::vector<Token, std::allocator<Token>>::size_type>(i) + 2).type == Token_T::semi)
				{
					output.append("\tmov rax, 60\n");
					output.append("\tmov rdi, " + tokens.at
						(static_cast<std::vector<Token, std::allocator<Token>>::size_type>(i) + 1).value.value() + "\n");
					output.append("\tsyscall");
				}
			}
		}
	}
	return output;
}