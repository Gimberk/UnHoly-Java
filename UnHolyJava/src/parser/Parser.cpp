#include "Parser.h"
#include <iostream>

std::vector<char>* Parser::getSource() {
	if (generated) return &source;
	std::cout << "Invalid Source: Source Not Generated!";
	return nullptr;
}

bool Parser::generateSource(std::string input) {
	if (input.size() == 0) return false;
	for (char car : input) source.push_back(car);
	generated = true;
	return true;
}