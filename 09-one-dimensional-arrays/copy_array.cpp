#include <iostream>

int main() {
    int size;
    std::cout << "Enter array size (1-100): ";
    if (!(std::cin >> size) || size < 1 || size > 100) {
        std::cout << "Array size must be from 1 to 100.\n";
        return 0;
    }

    int original[100];
    int copy[100];
    for (int i = 0; i < size; ++i) {
        if (!(std::cin >> original[i])) {
            std::cout << "Enter exactly " << size << " whole numbers.\n";
            return 0;
        }
        copy[i] = original[i];
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Enter only the array values.\n";
        return 0;
    }

    std::cout << "Copied array: ";
    for (int i = 0; i < size; ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << copy[i];
    }
    std::cout << '\n';
}
