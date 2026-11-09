#include <iostream>

int main() {
    int size;
    std::cout << "Enter array size (1-100): ";
    if (!(std::cin >> size) || size < 1 || size > 100) {
        std::cout << "Array size must be from 1 to 100.\n";
        return 0;
    }

    int values[100];
    for (int i = 0; i < size; ++i) {
        if (!(std::cin >> values[i])) {
            std::cout << "Enter exactly " << size << " whole numbers.\n";
            return 0;
        }
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Enter only the array values.\n";
        return 0;
    }

    int unique[100];
    int uniqueCount = 0;
    for (int i = 0; i < size; ++i) {
        bool alreadySeen = false;
        for (int j = 0; j < uniqueCount; ++j) {
            if (unique[j] == values[i]) {
                alreadySeen = true;
                break;
            }
        }
        if (!alreadySeen) {
            unique[uniqueCount++] = values[i];
        }
    }

    std::cout << "Array without duplicates: ";
    for (int i = 0; i < uniqueCount; ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << unique[i];
    }
    std::cout << '\n';
}
