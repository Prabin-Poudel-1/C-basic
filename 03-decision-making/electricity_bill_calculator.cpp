#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// Practice a progressive electricity bill calculation using fictional rates.
int main() {
    std::cout << "Enter units consumed: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream input(line);
    double units;
    char extra;
    if (!(input >> units) || (input >> extra)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (!std::isfinite(units) || units < 0) {
        std::cout << "Units must be finite and non-negative.\n";
        return 0;
    }

    // Example rates per unit: first 100 at 1.50, next 100 at 2.50, rest at 4.00.
    double bill;
    if (units <= 100) {
        bill = units * 1.50;
    } else if (units <= 200) {
        bill = 100 * 1.50 + (units - 100) * 2.50;
    } else {
        bill = 100 * 1.50 + 100 * 2.50 + (units - 200) * 4.00;
    }
    if (!std::isfinite(bill)) {
        std::cout << "Bill is too large.\n";
        return 0;
    }
    std::cout << std::fixed << std::setprecision(2)
              << "Example bill: " << bill << " currency units\n";
    return 0;
}
