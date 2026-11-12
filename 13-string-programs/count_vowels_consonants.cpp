#include <iostream>
#include <string>

int main() {
    std::string text;
    std::cout << "Enter a line of text: ";
    if (!std::getline(std::cin, text)) {
        std::cout << "No line was provided.\n";
        return 0;
    }

    int vowels = 0;
    int consonants = 0;
    for (char character : text) {
        if (character >= 'A' && character <= 'Z') {
            character = static_cast<char>(character + ('a' - 'A'));
        }
        if (character >= 'a' && character <= 'z') {
            if (character == 'a' || character == 'e' || character == 'i'
                || character == 'o' || character == 'u') {
                ++vowels;
            } else {
                ++consonants;
            }
        }
    }

    std::cout << "Vowels: " << vowels << '\n';
    std::cout << "Consonants: " << consonants << '\n';
}
