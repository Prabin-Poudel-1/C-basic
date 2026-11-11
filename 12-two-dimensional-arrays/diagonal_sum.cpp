#include <iostream>

int main() {
    int size;
    std::cout << "Enter square matrix size (1-10): ";
    if (!(std::cin >> size) || size < 1 || size > 10) {
        std::cout << "Matrix size must be from 1 to 10.\n";
        return 0;
    }

    long long diagonalSum = 0;
    std::cout << "Enter matrix values row by row:\n";
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            int value;
            if (!(std::cin >> value)) {
                std::cout << "Enter exactly " << size * size << " whole numbers.\n";
                return 0;
            }
            if (row == column) {
                diagonalSum += value;
            }
        }
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Enter only the matrix size and values.\n";
        return 0;
    }

    std::cout << "Main diagonal sum: " << diagonalSum << '\n';
}
