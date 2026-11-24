#include <iostream>
#include <string>
#include <vector>

bool isBalanced(const std::string& expression) {
    std::vector<char> stack;
    for (char current : expression) {
        if (current == '(' || current == '[' || current == '{') {
            stack.push_back(current);
        } else if (current == ')' || current == ']' || current == '}') {
            if (stack.empty()) {
                return false;
            }
            const char opening = stack.back();
            stack.pop_back();
            if ((current == ')' && opening != '(') || (current == ']' && opening != '[')
                    || (current == '}' && opening != '{')) {
                return false;
            }
        }
    }
    return stack.empty();
}

int main() {
    std::string expression;
    std::cout << "Enter an expression: ";
    if (!std::getline(std::cin, expression)) {
        std::cout << "An expression is required.\n";
        return 0;
    }
    std::string extra;
    if (std::getline(std::cin, extra) && extra.find_first_not_of(" \t\r") != std::string::npos) {
        std::cout << "Enter one expression on a single line.\n";
        return 0;
    }
    std::cout << (isBalanced(expression) ? "Parentheses are balanced.\n"
                                         : "Parentheses are not balanced.\n");
}
