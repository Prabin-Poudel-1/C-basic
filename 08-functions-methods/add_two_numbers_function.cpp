#include <iostream>
long long add(int first, int second) { return static_cast<long long>(first) + second; }
int main() {
    int first, second; std::cout << "Enter two 32-bit whole numbers: ";
    if (!(std::cin >> first >> second)) { std::cout << "Enter two 32-bit whole numbers.\n"; return 0; }
    if (std::cin >> std::ws && std::cin.peek() != std::char_traits<char>::eof()) { std::cout << "Enter only two whole numbers.\n"; return 0; }
    std::cout << "Sum: " << add(first, second) << '\n';
}
