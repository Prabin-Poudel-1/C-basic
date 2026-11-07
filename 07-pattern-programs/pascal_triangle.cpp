#include <iostream>
int main() {
    int rows; std::cout << "Enter number of rows (1-20): ";
    if (!(std::cin >> rows) || (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) || rows < 1 || rows > 20) { std::cout << "Rows must be one whole number from 1 to 20.\n"; return 0; }
    for (int row = 0; row < rows; ++row) {
        long long value = 1;
        for (int space = 0; space < rows - row - 1; ++space) std::cout << ' ';
        for (int column = 0; column <= row; ++column) {
            std::cout << value << ' ';
            value = value * (row - column) / (column + 1);
        }
        std::cout << '\n';
    }
}
