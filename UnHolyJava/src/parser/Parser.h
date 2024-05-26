#pragma once
#include <string>
#include <vector>

#include "Lexeme.h"

class Parser
{
public:
	std::vector<Lexeme>* getSource();
	bool generateSource(std::string);
private:
	std::vector<Lexeme> source;
	bool generated = false;
};

