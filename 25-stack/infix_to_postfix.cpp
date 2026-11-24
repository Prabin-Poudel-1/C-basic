#include <cctype>
#include <iostream>
#include <string>
#include <vector>

int precedence(char operation) {
    if (operation == '^') {
        return 3;
    }
    if (operation == '*' || operation == '/') {
        return 2;
    }
    return 1;
}

bool isOperator(char character) {
    return character == '+' || character == '-' || character == '*'
            || character == '/' || character == '^';
}

bool toPostfix(const std::string& expression, std::string& result) {
    std::vector<char> operators;
    std::vector<std::string> output;
    bool expectingOperand = true;
    std::size_t i = 0;

    while (i < expression.size()) {
        const unsigned char current = static_cast<unsigned char>(expression[i]);
        if (std::isspace(current)) {
            ++i;
        } else if (std::isalnum(current)) {
            if (!expectingOperand) {
                return false;
            }
            const std::size_t start = i++;
            while (i < expression.size()
                    && std::isalnum(static_cast<unsigned char>(expression[i]))) {
                ++i;
            }
            output.push_back(expression.substr(start, i - start));
            expectingOperand = false;
        } else if (expression[i] == '(') {
            if (!expectingOperand) {
                return false;
            }
            operators.push_back('(');
            expectingOperand = true;
            ++i;
        } else if (expression[i] == ')') {
            if (expectingOperand) {
                return false;
            }
            while (!operators.empty() && operators.back() != '(') {
                output.emplace_back(1, operators.back());
                operators.pop_back();
            }
            if (operators.empty()) {
                return false;
            }
            operators.pop_back();
            expectingOperand = false;
            ++i;
        } else if (isOperator(expression[i])) {
            const char currentOperator = expression[i];
            if (expectingOperand) {
                return false;
            }
            while (!operators.empty() && operators.back() != '(') {
                const char top = operators.back();
                const bool higherPrecedence = precedence(top) > precedence(currentOperator);
                const bool samePrecedenceAndLeftAssociative = precedence(top) == precedence(currentOperator)
                        && currentOperator != '^';
                if (!higherPrecedence && !samePrecedenceAndLeftAssociative) {
                    break;
                }
                output.emplace_back(1, top);
                operators.pop_back();
            }
            operators.push_back(currentOperator);
            expectingOperand = true;
            ++i;
        } else {
            return false;
        }
    }

    if (expectingOperand || output.empty()) {
        return false;
    }
    while (!operators.empty()) {
        if (operators.back() == '(') {
            return false;
        }
        output.emplace_back(1, operators.back());
        operators.pop_back();
    }
    for (std::size_t token = 0; token < output.size(); ++token) {
        if (token > 0) {
            result += ' ';
        }
        result += output[token];
    }
    return true;
}

int main() {
    std::string expression;
    std::cout << "Enter an infix expression: ";
    if (!std::getline(std::cin, expression)) {
        std::cout << "An expression is required.\n";
        return 0;
    }
    std::string extra;
    if (std::getline(std::cin, extra) && extra.find_first_not_of(" \t\r") != std::string::npos) {
        std::cout << "Enter one expression on a single line.\n";
        return 0;
    }
    std::string result;
    if (!toPostfix(expression, result)) {
        std::cout << "Invalid infix expression.\n";
    } else {
        std::cout << "Postfix: " << result << '\n';
    }
}
