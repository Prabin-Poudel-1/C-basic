#include <iostream>
#include <string>

int main() {
    std::string first;
    std::string second;
    std::cout << "Enter the first string: ";
    if (!std::getline(std::cin, first)) {
        std::cout << "Two lines are required.\n";
        return 0;
    }
    std::cout << "Enter the second string: ";
    if (!std::getline(std::cin, second)) {
        std::cout << "Two lines are required.\n";
        return 0;
    }

    std::cout << "Concatenated string: " << first + second << '\n';
}
