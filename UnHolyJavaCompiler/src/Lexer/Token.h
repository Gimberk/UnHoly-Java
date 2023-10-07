#pragma once

#include <optional>
#include <iostream>

enum class Token_T
{
    _return,
    int_lit,
    semi
};

struct Token
{
    Token_T type;
    std::optional<std::string> value;
};