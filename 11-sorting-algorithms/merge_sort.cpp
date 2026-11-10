#include <iostream>

void mergeSort(int values[], int temporary[], int left, int right) {
    if (left >= right) {
        return;
    }
    int middle = left + (right - left) / 2;
    mergeSort(values, temporary, left, middle);
    mergeSort(values, temporary, middle + 1, right);

    int first = left;
    int second = middle + 1;
    int next = left;
    while (first <= middle && second <= right) {
        if (values[first] <= values[second]) {
            temporary[next++] = values[first++];
        } else {
            temporary[next++] = values[second++];
        }
    }
    while (first <= middle) {
        temporary[next++] = values[first++];
    }
    while (second <= right) {
        temporary[next++] = values[second++];
    }
    for (int i = left; i <= right; ++i) {
        values[i] = temporary[i];
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

    int temporary[100];
    mergeSort(values, temporary, 0, size - 1);
    std::cout << "Sorted array: ";
    for (int i = 0; i < size; ++i) {
        if (i > 0) std::cout << ' ';
        std::cout << values[i];
    }
    std::cout << '\n';
}
