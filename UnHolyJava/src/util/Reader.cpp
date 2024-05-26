#include "Reader.h"
#include <fstream>

int Reader::put(std::string content, std::string path) {
	try {
		std::ofstream file;
		file.open(path);
		file << content;
		file.close();
	}
	catch(int error){
		std::cout << "Error Writing File: " << path << " Error Code: " << error << "\n";
		return error;
	}
	return 0;
}

std::string Reader::get(std::string path) {
	std::string line;
	std::string out;
	std::ifstream file(path);
	if (file.is_open()) {
		while (std::getline(file, line)) {
			out.append(line);
		}
	}
	else std::cout << "Error Reading File: " << path << "\n";
	return out;
}