#include <iostream>
#include <limits>

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

    int largest = std::numeric_limits<int>::min();
    std::cout << "Enter matrix values row by row:\n";
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < columns; ++column) {
            int value;
            if (!(std::cin >> value)) {
                std::cout << "Enter exactly " << rows * columns << " whole numbers.\n";
                return 0;
            }
            if (value > largest) {
                largest = value;
            }
        }
    }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) {
        std::cout << "Enter only the dimensions and matrix values.\n";
        return 0;
    }

    std::cout << "Largest matrix element: " << largest << '\n';
}
