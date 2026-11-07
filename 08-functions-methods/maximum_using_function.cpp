#include <iostream>

int maximum(int first, int second) {
    return first > second ? first : second;
}

int main() {
    int first, second;
    std::cout << "Enter two whole numbers: ";
    if (!(std::cin >> first >> second)) { std::cout << "Enter two 32-bit whole numbers.\n"; return 0; }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) { std::cout << "Enter only two whole numbers.\n"; return 0; }
    std::cout << "Maximum: " << maximum(first, second) << '\n';
}
