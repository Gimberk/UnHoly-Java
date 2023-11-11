#pragma once

#include <optional>
#include <iostream>
#include <vector>

enum class Token_T
{
    _return,
    int_lit,
    semi,
    none
};

struct Token
{
    Token_T type;
    std::optional<std::string> value;
    std::vector<Token_T> requisites;
};