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

    for (int pass = 0; pass < size - 1; ++pass) {
        bool swapped = false;
        for (int i = 0; i < size - 1 - pass; ++i) {
            if (values[i] > values[i + 1]) {
                int temporary = values[i];
                values[i] = values[i + 1];
                values[i + 1] = temporary;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
    }

    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << values[i];
    }
    std::cout << '\n';
}
