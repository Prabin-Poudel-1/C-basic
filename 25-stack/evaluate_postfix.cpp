#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

bool evaluate(const std::string& expression, double& result) {
    std::istringstream tokens(expression);
    std::vector<double> values;
    std::string token;
    bool hasToken = false;

    while (tokens >> token) {
        hasToken = true;
        if (token.size() == 1 && std::string("+-*/").find(token[0]) != std::string::npos) {
            if (values.size() < 2) {
                return false;
            }
            const double right = values.back();
            values.pop_back();
            const double left = values.back();
            values.pop_back();
            double currentResult;
            switch (token[0]) {
                case '+': currentResult = left + right; break;
                case '-': currentResult = left - right; break;
                case '*': currentResult = left * right; break;
                default:
                    if (right == 0) {
                        return false;
                    }
                    currentResult = left / right;
            }
            if (!std::isfinite(currentResult)) {
                return false;
            }
            values.push_back(currentResult);
        } else {
            try {
                std::size_t parsed = 0;
                const double number = std::stod(token, &parsed);
                if (parsed != token.size() || !std::isfinite(number)) {
                    return false;
                }
                values.push_back(number);
            } catch (const std::exception&) {
                return false;
            }
        }
    }
    if (!hasToken || values.size() != 1) {
        return false;
    }
    result = values.back();
    return true;
}

int main() {
    std::string expression;
    std::cout << "Enter a space-separated postfix expression: ";
    if (!std::getline(std::cin, expression)) {
        std::cout << "An expression is required.\n";
        return 0;
    }
    std::string extra;
    if (std::getline(std::cin, extra) && extra.find_first_not_of(" \t\r") != std::string::npos) {
        std::cout << "Enter one expression on a single line.\n";
        return 0;
    }
    double result;
    if (!evaluate(expression, result)) {
        std::cout << "Invalid postfix expression or division by zero.\n";
    } else {
        std::cout << "Result: " << result << '\n';
    }
}
