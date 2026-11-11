#include <iostream>

int main() {
    int rows, columns;
    std::cout << "Enter rows and columns (1-10 each): ";
    if (!(std::cin >> rows >> columns)) {
        std::cout << "Enter row and column counts from 1 to 10.\n";
        return 0;
    }
    if (rows < 1 || rows > 10 || columns < 1 || columns > 10) {
        std::cout << "Rows and columns must each be from 1 to 10.\n";
        return 0;
    }

    int first[10][10];
    int second[10][10];
    std::cout << "Enter first matrix values row by row:\n";
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (!(std::cin >> first[row][column])) {
                std::cout << "Enter all values for both matrices.\n";
                return 0;
            }
        }
    }
    std::cout << "Enter second matrix values row by row:\n";
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (!(std::cin >> second[row][column])) {
                std::cout << "Enter all values for both matrices.\n";
                return 0;
            }
        }
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Enter only the dimensions and matrix values.\n";
        return 0;
    }

    std::cout << "Difference matrix (first minus second):\n";
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            if (column > 0) std::cout << ' ';
            std::cout << static_cast<long long>(first[row][column]) - second[row][column];
        }
        std::cout << '\n';
    }
}
