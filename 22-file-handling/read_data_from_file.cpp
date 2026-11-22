#include <fstream>
#include <iostream>
#include <string>

int main() {
    std::ifstream input("practice_data.txt");
    if (!input) {
        std::cout << "Could not open practice_data.txt for reading.\n";
        return 0;
    }

    std::string line;
    bool foundLine = false;
    std::cout << "File contents:\n";
    while (std::getline(input, line)) {
        std::cout << line << '\n';
        foundLine = true;
    }
    if (!input.eof()) {
        std::cout << "An error occurred while reading the file.\n";
        return 0;
    }
    if (!foundLine) {
        std::cout << "(File is empty.)\n";
    }
}
