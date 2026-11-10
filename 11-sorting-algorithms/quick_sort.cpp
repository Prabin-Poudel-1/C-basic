#include <iostream>

int partition(int values[], int low, int high) {
    int pivot = values[high];
    int smallerEnd = low - 1;
    for (int current = low; current < high; ++current) {
        if (values[current] <= pivot) {
            ++smallerEnd;
            int temporary = values[smallerEnd];
            values[smallerEnd] = values[current];
            values[current] = temporary;
        }
    }
    int temporary = values[smallerEnd + 1];
    values[smallerEnd + 1] = values[high];
    values[high] = temporary;
    return smallerEnd + 1;
}

void quickSort(int values[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(values, low, high);
        quickSort(values, low, pivotIndex - 1);
        quickSort(values, pivotIndex + 1, high);
    }
}

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

    quickSort(values, 0, size - 1);
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << values[i];
    }
    std::cout << '\n';
}
