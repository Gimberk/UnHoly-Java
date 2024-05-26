#include "util/Reader.h"
#include "parser/Parser.h"

int main()
{
	using namespace std;

	std::string input = Reader::get("C:\\Users\\james\\Downloads\\hi.txt");

	Parser parser;
	if (!parser.generateSource(input)) return -1;

	vector<char>* ref = parser.getSource();
	if (ref == nullptr) return -2;

	for (char c : *(ref)) {
		cout << c << '\n';
	}
}
