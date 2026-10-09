#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// Calculate the arithmetic mean of a user-specified number of values.
int main() {
    std::cout << "Enter count on its own line: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream countInput(line);
    int count;
    char extra;
    if (!(countInput >> count) || (countInput >> extra)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (count <= 0) {
        std::cout << "Count must be positive.\n";
        return 0;
    }

    std::cout << "Enter " << count << " numbers:\n";
    double sum = 0;
    for (int i = 0; i < count; i++) {
        double value;
        if (!(std::cin >> value)) {
            std::cout << "Invalid input.\n";
            return 0;
        }
        if (!std::isfinite(value)) {
            std::cout << "Numbers must be finite.\n";
            return 0;
        }
        sum += value;
        if (!std::isfinite(sum)) {
            std::cout << "Sum is too large.\n";
            return 0;
        }
    }

    // Arithmetic mean = sum of all values divided by their count.
    double average = sum / count;
    std::cout << std::fixed << std::setprecision(2) << "Average: " << average << '\n';
    return 0;
}
