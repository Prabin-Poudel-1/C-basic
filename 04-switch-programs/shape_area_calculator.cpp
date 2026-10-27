#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

// Read one finite number from the next input line.
bool readNumber(double& value) {
    std::string line;
    if (!std::getline(std::cin, line)) return false;
    std::istringstream input(line);
    char extra;
    return (input >> value) && !(input >> extra) && std::isfinite(value);
}

// Calculate rectangle, circle, or triangle area using a switch.
int main() {
    std::cout << "1. Rectangle\n2. Circle\n3. Triangle\nChoose a shape: ";
    std::string line;
    std::getline(std::cin, line);
    std::istringstream choiceInput(line);
    int choice;
    char extra;
    if (!(choiceInput >> choice) || (choiceInput >> extra)) {
        std::cout << "Invalid input.\n";
        return 0;
    }

    double first, second, area;
    switch (choice) {
        case 1:
            std::cout << "Enter length and width: ";
            if (!readNumber(first) || !readNumber(second)) {
                std::cout << "Invalid input. Dimensions must be finite.\n";
                return 0;
            }
            if (first < 0 || second < 0) {
                std::cout << "Dimensions must be finite and non-negative.\n";
                return 0;
            }
            area = first * second;
            break;
        case 2:
            std::cout << "Enter radius: ";
            if (!readNumber(first)) {
                std::cout << "Invalid input. Radius must be finite.\n";
                return 0;
            }
            if (first < 0) {
                std::cout << "Radius must be finite and non-negative.\n";
                return 0;
            }
            area = std::acos(-1.0) * first * first;
            break;
        case 3:
            std::cout << "Enter base and height: ";
            if (!readNumber(first) || !readNumber(second)) {
                std::cout << "Invalid input. Dimensions must be finite.\n";
                return 0;
            }
            if (first < 0 || second < 0) {
                std::cout << "Dimensions must be finite and non-negative.\n";
                return 0;
            }
            area = 0.5 * first * second;
            break;
        default:
            std::cout << "Invalid shape choice.\n";
            return 0;
    }
    if (!std::isfinite(area)) {
        std::cout << "Area is too large.\n";
        return 0;
    }
    std::cout << std::fixed << std::setprecision(2) << "Area: " << area << '\n';
    return 0;
}
