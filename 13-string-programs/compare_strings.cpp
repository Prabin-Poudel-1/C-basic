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

    if (first == second) {
        std::cout << "Strings are equal\n";
    } else if (first < second) {
        std::cout << "First string comes before the second\n";
    } else {
        std::cout << "First string comes after the second\n";
    }
}
