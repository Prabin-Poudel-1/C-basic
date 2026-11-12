#include <iostream>
#include <string>

bool isAsciiLetterOrDigit(char character) {
    return (character >= 'A' && character <= 'Z')
        || (character >= 'a' && character <= 'z')
        || (character >= '0' && character <= '9');
}

char toLowerAscii(char character) {
    if (character >= 'A' && character <= 'Z') {
        return static_cast<char>(character + ('a' - 'A'));
    }
    return character;
}

int main() {
    std::string text;
    std::cout << "Enter a line of text: ";
    if (!std::getline(std::cin, text)) {
        std::cout << "No line was provided.\n";
        return 0;
    }

    int left = 0;
    int right = static_cast<int>(text.length()) - 1;
    bool palindrome = true;
    while (left < right) {
        while (left < right && !isAsciiLetterOrDigit(text[left])) {
            ++left;
        }
        while (left < right && !isAsciiLetterOrDigit(text[right])) {
            --right;
        }
        if (toLowerAscii(text[left]) != toLowerAscii(text[right])) {
            palindrome = false;
            break;
        }
        ++left;
        --right;
    }

    std::cout << (palindrome ? "Palindrome\n" : "Not a palindrome\n");
}
