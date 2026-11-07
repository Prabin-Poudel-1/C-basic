#include <iostream>
void printRow(int spaces, int stars) { for (int i = 0; i < spaces; ++i) std::cout << ' '; for (int i = 0; i < stars; ++i) std::cout << '*'; std::cout << '\n'; }
int main() {
    int height; std::cout << "Enter half-height (1-25): ";
    if (!(std::cin >> height) || (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) || height < 1 || height > 25) { std::cout << "Half-height must be one whole number from 1 to 25.\n"; return 0; }
    for (int row = 1; row <= height; ++row) printRow(height - row, 2 * row - 1);
    for (int row = height - 1; row >= 1; --row) printRow(height - row, 2 * row - 1);
}
