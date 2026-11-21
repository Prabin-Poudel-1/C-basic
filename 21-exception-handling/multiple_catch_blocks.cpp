#include <cmath>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    std::string dividendText, divisorText, extraInput;
    std::cout << "Enter dividend and divisor: ";
    if (!(std::cin >> dividendText >> divisorText)) {
        std::cout << "Please enter two numbers.\n";
        return 0;
    }
    if (std::cin >> extraInput) {
        std::cout << "Enter exactly two numbers.\n";
        return 0;
    }

    try {
        std::size_t dividendLength = 0;
        std::size_t divisorLength = 0;
        double dividend = std::stod(dividendText, &dividendLength);
        double divisor = std::stod(divisorText, &divisorLength);
        if (dividendLength != dividendText.length() || divisorLength != divisorText.length()
                || !std::isfinite(dividend) || !std::isfinite(divisor)) {
            throw std::invalid_argument("Both values must be finite numbers.");
        }
        if (divisor == 0) {
            throw std::runtime_error("Division by zero is not allowed.");
        }
        double result = dividend / divisor;
        if (!std::isfinite(result)) {
            throw std::runtime_error("The result is too large to display.");
        }
        std::cout << std::fixed << std::setprecision(2) << "Result: " << result << '\n';
    } catch (const std::invalid_argument& error) {
        std::cout << "Invalid input: " << error.what() << '\n';
    } catch (const std::out_of_range&) {
        std::cout << "A value is outside the supported range.\n";
    } catch (const std::runtime_error& error) {
        std::cout << error.what() << '\n';
    }
}
