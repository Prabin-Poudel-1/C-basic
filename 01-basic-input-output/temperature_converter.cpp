#include <iostream>
#include <string>
#include <iomanip>

// Convert Celsius and Fahrenheit in both directions.
int main() {
    std::string unit;
    double temperature;
    std::cout << "Enter the source unit (C or F) and temperature: ";
    if (!(std::cin >> unit >> temperature)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    std::cout << std::fixed << std::setprecision(2);
    if (unit == "C" || unit == "c") {
        double fahrenheit = temperature * 9.0 / 5.0 + 32;
        std::cout << "Fahrenheit: " << fahrenheit << '\n';
    } else if (unit == "F" || unit == "f") {
        double celsius = (temperature - 32) * 5.0 / 9.0;
        std::cout << "Celsius: " << celsius << '\n';
    } else {
        std::cout << "Unsupported unit. Use C or F.\n";
    }
    return 0;
}
