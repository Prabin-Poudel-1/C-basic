#include <iostream>
#include <sstream>
#include <string>

int main() {
    const int capacity = 5;
    int stack[capacity];
    int top = -1;
    std::string choice;

    while (true) {
        std::cout << "1. Push  2. Pop  3. Display  0. Exit\n";
        std::cout << "Choice: ";
        if (!std::getline(std::cin, choice)) {
            break;
        }
        if (choice == "0") {
            break;
        } else if (choice == "1") {
            if (top == capacity - 1) {
                std::cout << "Stack is full.\n";
                continue;
            }
            std::string line;
            std::cout << "Integer to push: ";
            if (!std::getline(std::cin, line)) {
                break;
            }
            std::istringstream valueInput(line);
            int value;
            std::string extra;
            if (!(valueInput >> value) || (valueInput >> extra)) {
                std::cout << "Enter a whole number.\n";
                continue;
            }
            stack[++top] = value;
            std::cout << "Pushed " << value << ".\n";
        } else if (choice == "2") {
            if (top == -1) {
                std::cout << "Stack is empty.\n";
            } else {
                std::cout << "Popped " << stack[top--] << ".\n";
            }
        } else if (choice == "3") {
            if (top == -1) {
                std::cout << "Stack is empty.\n";
            } else {
                std::cout << "Top to bottom: ";
                for (int i = top; i >= 0; --i) {
                    std::cout << stack[i] << (i == 0 ? "" : " ");
                }
                std::cout << '\n';
            }
        } else {
            std::cout << "Choose 1, 2, 3, or 0.\n";
        }
    }
}
