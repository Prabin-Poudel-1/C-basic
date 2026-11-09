#include <iostream>

int main() {
    int firstSize;
    std::cout << "Enter first array size (1-100): ";
    if (!(std::cin >> firstSize) || firstSize < 1 || firstSize > 100) {
        std::cout << "Array size must be from 1 to 100.\n";
        return 0;
    }

    int merged[200];
    for (int i = 0; i < firstSize; ++i) {
        if (!(std::cin >> merged[i])) {
            std::cout << "Enter all values in the first array.\n";
            return 0;
        }
    }

    int secondSize;
    std::cout << "Enter second array size (1-100): ";
    if (!(std::cin >> secondSize) || secondSize < 1 || secondSize > 100) {
        std::cout << "Array size must be from 1 to 100.\n";
        return 0;
    }
    for (int i = 0; i < secondSize; ++i) {
        if (!(std::cin >> merged[firstSize + i])) {
            std::cout << "Enter all values in the second array.\n";
            return 0;
        }
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Enter only the two array sizes and their values.\n";
        return 0;
    }

    std::cout << "Merged array: ";
    for (int i = 0; i < firstSize + secondSize; ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << merged[i];
    }
    std::cout << '\n';
}
