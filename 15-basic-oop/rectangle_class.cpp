#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Rectangle {
public:
    double length;
    double width;

    double area() const {
        return length * width;
    }

    double perimeter() const {
        return 2 * (length + width);
    }
};

int main() {
    Rectangle rectangle;
    std::string line;
    std::string extra;
    std::cout << "Enter non-negative length and width: ";
    if (!std::getline(std::cin, line)) {
        std::cout << "Length and width must be finite, non-negative numbers.\n";
        return 0;
    }
    std::istringstream input(line);
    if (!(input >> rectangle.length >> rectangle.width) || (input >> extra) ||
        !std::isfinite(rectangle.length) || !std::isfinite(rectangle.width) ||
        rectangle.length < 0 || rectangle.width < 0 ||
        !std::isfinite(rectangle.area()) || !std::isfinite(rectangle.perimeter())) {
        std::cout << "Length and width must be finite, non-negative numbers.\n";
        return 0;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Area: " << rectangle.area() << '\n';
    std::cout << "Perimeter: " << rectangle.perimeter() << '\n';
}
