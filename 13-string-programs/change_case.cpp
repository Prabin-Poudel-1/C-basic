#include <iostream>
#include <string>

std::string toUpperAscii(const std::string& text) {
    std::string result = text;
    for (char& character : result) {
        if (character >= 'a' && character <= 'z') {
            character = static_cast<char>(character - ('a' - 'A'));
        }
    }
    return result;
}

std::string toLowerAscii(const std::string& text) {
    std::string result = text;
    for (char& character : result) {
        if (character >= 'A' && character <= 'Z') {
            character = static_cast<char>(character + ('a' - 'A'));
        }
    }
    return result;
}

int main() {
    std::string text;
    std::cout << "Enter a line of text: ";
    if (!std::getline(std::cin, text)) {
        std::cout << "No line was provided.\n";
        return 0;
    }

    std::cout << "Uppercase: " << toUpperAscii(text) << '\n';
    std::cout << "Lowercase: " << toLowerAscii(text) << '\n';
}
