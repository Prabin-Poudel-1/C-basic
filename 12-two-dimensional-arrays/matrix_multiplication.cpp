#include <iostream>

int main() {
    int firstRows, firstColumns;
    std::cout << "Enter first matrix rows and columns (1-10 each): ";
    if (!(std::cin >> firstRows >> firstColumns)) {
        std::cout << "Enter dimensions from 1 to 10.\n";
        return 0;
    }
    if (firstRows < 1 || firstRows > 10 || firstColumns < 1 || firstColumns > 10) {
        std::cout << "Dimensions must each be from 1 to 10.\n";
        return 0;
    }

    int first[10][10];
    std::cout << "Enter first matrix values row by row:\n";
    for (int row = 0; row < firstRows; ++row) {
        for (int column = 0; column < firstColumns; ++column) {
            if (!(std::cin >> first[row][column])) {
                std::cout << "Enter all matrix values.\n";
                return 0;
            }
        }
    }

    int secondRows, secondColumns;
    std::cout << "Enter second matrix rows and columns (1-10 each): ";
    if (!(std::cin >> secondRows >> secondColumns)) {
        std::cout << "Enter dimensions from 1 to 10.\n";
        return 0;
    }
    if (secondRows < 1 || secondRows > 10 || secondColumns < 1 || secondColumns > 10) {
        std::cout << "Dimensions must each be from 1 to 10.\n";
        return 0;
    }
    if (firstColumns != secondRows) {
        std::cout << "The first matrix columns must equal the second matrix rows.\n";
        return 0;
    }

    int second[10][10];
    std::cout << "Enter second matrix values row by row:\n";
    for (int row = 0; row < secondRows; ++row) {
        for (int column = 0; column < secondColumns; ++column) {
            if (!(std::cin >> second[row][column])) {
                std::cout << "Enter all matrix values.\n";
                return 0;
            }
        }
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Enter only the dimensions and matrix values.\n";
        return 0;
    }

    std::cout << "Product matrix:\n";
    for (int row = 0; row < firstRows; ++row) {
        for (int column = 0; column < secondColumns; ++column) {
            long long sum = 0;
            for (int k = 0; k < firstColumns; ++k) {
                sum += static_cast<long long>(first[row][k]) * second[k][column];
            }
            if (column > 0) std::cout << ' ';
            std::cout << sum;
        }
        std::cout << '\n';
    }
}
