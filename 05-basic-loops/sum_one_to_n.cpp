#include <iostream>
#include <sstream>
#include <string>

// Calculate the sum of integers from 1 through n.
int main() {
    constexpr long long maxN = 4294967295LL;
    std::cout << "Enter n (0 to " << maxN << "): ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    long long n;
    char extra;
    if (!(input >> n) || (input >> extra)) {
        std::cout << "Invalid input. Enter a whole number.\n";
        return 0;
    }
    if (n < 0 || n > maxN) {
        std::cout << "n must be between 0 and " << maxN << ".\n";
        return 0;
    }
    // Divide an even factor first so the multiplication stays in range.
    long long first = n;
    long long second = n + 1;
    if (first % 2 == 0) first /= 2;
    else second /= 2;
    std::cout << "Sum: " << first * second << '\n';
    return 0;
}
