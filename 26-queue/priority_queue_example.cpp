#include <iostream>
#include <queue>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::priority_queue<int> priorities;
    std::string choice;
    while (true) {
        std::cout << "1. Add priority  2. Remove highest  3. Display order  0. Exit\n";
        std::cout << "Choice: ";
        if (!std::getline(std::cin, choice)) {
            break;
        }
        if (choice == "0") {
            break;
        } else if (choice == "1") {
            std::string line;
            std::cout << "Integer priority: ";
            if (!std::getline(std::cin, line)) {
                break;
            }
            std::istringstream valueInput(line);
            int priority;
            std::string extra;
            if (!(valueInput >> priority) || (valueInput >> extra)) {
                std::cout << "Enter a whole number.\n";
            } else {
                priorities.push(priority);
                std::cout << "Added priority " << priority << ".\n";
            }
        } else if (choice == "2") {
            if (priorities.empty()) {
                std::cout << "Priority queue is empty.\n";
            } else {
                std::cout << "Removed priority " << priorities.top() << ".\n";
                priorities.pop();
            }
        } else if (choice == "3") {
            if (priorities.empty()) {
                std::cout << "Priority queue is empty.\n";
            } else {
                std::priority_queue<int> ordered = priorities;
                std::cout << "Highest to lowest: ";
                bool first = true;
                while (!ordered.empty()) {
                    if (!first) {
                        std::cout << ' ';
                    }
                    std::cout << ordered.top();
                    ordered.pop();
                    first = false;
                }
                std::cout << '\n';
            }
        } else {
            std::cout << "Choose 1, 2, 3, or 0.\n";
        }
    }
}
