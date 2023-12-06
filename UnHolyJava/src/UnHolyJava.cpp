#include <fstream>
#include <sstream>
#include <iostream>
int main()
{
    std::string content;
    {
        std::stringstream contents_stream;
        std::fstream input("../UnHolyJava/content/Text.uhj", std::ios::in);
        contents_stream << input.rdbuf();
        content = contents_stream.str();
    }
    
    std::cout << content;
}