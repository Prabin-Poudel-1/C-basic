#include <iostream>
#include <string>

int main() {
    std::string text;
    std::cout << "Enter a line of text: ";
    if (!std::getline(std::cin, text)) {
        std::cout << "No line was provided.\n";
        return 0;
    }

    std::string withoutSpaces;
    for (char character : text) {
        if (character != ' ') {
            withoutSpaces += character;
        }
    }
    std::cout << "Without spaces: " << withoutSpaces << '\n';
}
