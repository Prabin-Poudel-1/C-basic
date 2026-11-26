#include <iostream>
#include <sstream>
#include <string>
#include <vector>

void traverse(const std::vector<int>& tree, std::size_t index, std::vector<int>& order) {
    if (index >= tree.size()) {
        return;
    }
    traverse(tree, index * 2 + 1, order);
    order.push_back(tree[index]);
    traverse(tree, index * 2 + 2, order);
}

int main() {
    std::string line;
    std::cout << "Number of nodes (0 to 100): ";
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
    if (tree.empty()) {
        std::cout << "The tree is empty.\n";
        return 0;
    }

    std::vector<int> order;
    traverse(tree, 0, order);
    std::cout << "In-order traversal: ";
    for (std::size_t i = 0; i < order.size(); ++i) {
        std::cout << order[i] << (i + 1 == order.size() ? "" : " ");
    }
    std::cout << '\n';
}
