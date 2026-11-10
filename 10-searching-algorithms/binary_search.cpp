#include <iostream>

int main() {
    int size;
    std::cout << "Enter sorted array size (1-100): ";
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
        if (i > 0 && values[i] < values[i - 1]) {
            std::cout << "Values must be sorted in ascending order.\n";
            return 0;
        }
    }

    int target;
    if (!(std::cin >> target)) {
        std::cout << "Enter one target whole number.\n";
        return 0;
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Enter only the array values and target.\n";
        return 0;
    }

    int low = 0;
    int high = size - 1;
    int found = -1;
    while (low <= high) {
        int middle = low + (high - low) / 2;
        if (values[middle] == target) {
            found = middle;
            break;
        } else if (values[middle] < target) {
            low = middle + 1;
        } else {
            high = middle - 1;
        }
    }

    if (found == -1) {
        std::cout << "Not found\n";
    } else {
        std::cout << "Found at index " << found << '\n';
    }
}
