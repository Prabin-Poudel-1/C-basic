#include <iostream>

int main() {
    int size;
    std::cout << "Enter pattern size (1-50): ";
    if (!(std::cin >> size)) {
        std::cout << "Enter one whole number from 1 to 50.\n";
        return 0;
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Enter only one whole number.\n";
        return 0;
    }
    if (size < 1 || size > 50) {
        std::cout << "Size must be from 1 to 50.\n";
        return 0;
    }

    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            std::cout << "* ";
        }
        std::cout << '\n';
    }
    return 0;
}
