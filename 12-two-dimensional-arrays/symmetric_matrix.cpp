#include <iostream>

int main() {
    int size;
    std::cout << "Enter square matrix size (1-10): ";
    if (!(std::cin >> size) || size < 1 || size > 10) {
        std::cout << "Matrix size must be from 1 to 10.\n";
        return 0;
    }

    int matrix[10][10];
    std::cout << "Enter matrix values row by row:\n";
    for (int row = 0; row < size; ++row) {
        for (int column = 0; column < size; ++column) {
            if (!(std::cin >> matrix[row][column])) {
                std::cout << "Enter exactly " << size * size << " whole numbers.\n";
                return 0;
            }
        }
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Enter only the matrix size and values.\n";
        return 0;
    }

    bool symmetric = true;
    for (int row = 0; row < size && symmetric; ++row) {
        for (int column = row + 1; column < size; ++column) {
            if (matrix[row][column] != matrix[column][row]) {
                symmetric = false;
                break;
            }
        }
    }
    std::cout << (symmetric ? "Symmetric matrix\n" : "Not a symmetric matrix\n");
}
