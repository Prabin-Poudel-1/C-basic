#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string line;
    std::cout << "Number of tree nodes (0 to 100): ";
    if (!std::getline(std::cin, line)) {
        std::cout << "A node count is required.\n";
        return 0;
    }
    std::istringstream countInput(line);
    int count;
    std::string extra;
    if (!(countInput >> count) || (countInput >> extra) || count < 0 || count > 100) {
        std::cout << "Enter a whole number from 0 to 100.\n";
        return 0;
    }

    std::vector<int> tree;
    for (int i = 0; i < count; ++i) {
        std::cout << "Node value " << (i + 1) << ": ";
        if (!std::getline(std::cin, line)) {
            std::cout << "Tree input ended early.\n";
            return 0;
        }
        std::istringstream valueInput(line);
        int value;
        if (!(valueInput >> value) || (valueInput >> extra)) {
            std::cout << "Enter a whole number for every node.\n";
            return 0;
        }
        tree.push_back(value);
    }
    if (count == 0) {
        std::cout << "The tree is empty.\n";
        return 0;
    }

    std::cout << "Complete binary tree (array representation):\n";
    for (int i = 0; i < count; ++i) {
        std::cout << "Node " << tree[i] << ": left ";
        if (i * 2 + 1 < count) {
            std::cout << tree[i * 2 + 1];
        } else {
            std::cout << "none";
        }
        std::cout << ", right ";
        if (i * 2 + 2 < count) {
            std::cout << tree[i * 2 + 2];
        } else {
            std::cout << "none";
        }
        std::cout << '\n';
    }
}
