#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string text;
    std::cout << "Enter a line of text: ";
    if (!std::getline(std::cin, text)) {
        std::cout << "No line was provided.\n";
        return 0;
    }

    std::istringstream wordsInLine(text);
    std::string word;
    int wordCount = 0;
    while (wordsInLine >> word) {
        ++wordCount;
    }

    std::cout << "Word count: " << wordCount << '\n';
}
