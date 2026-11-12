#include <algorithm>
#include <iostream>
#include <string>

int main() {
    std::string text;
    std::cout << "Enter a line of text: ";
    if (!std::getline(std::cin, text)) {
        std::cout << "No line was provided.\n";
        return 0;
    }

    std::reverse(text.begin(), text.end());
    std::cout << "Reversed string: " << text << '\n';
}
