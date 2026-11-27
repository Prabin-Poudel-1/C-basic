#include <iostream>
#include <vector>

void postorder(const std::vector<int>& tree, std::size_t index) {
    if (index >= tree.size()) return;
    postorder(tree, 2 * index + 1);
    postorder(tree, 2 * index + 2);
    std::cout << tree[index] << ' ';
}

int main() {
    int count;
    std::cout << "Number of nodes (0-100): ";
    if (!(std::cin >> count) || count < 0 || count > 100) {
        std::cout << "Node count must be between 0 and 100.\n";
        return 1;
    }

    std::vector<int> tree(static_cast<std::size_t>(count));
    std::cout << "Enter node values in level order:\n";
    for (int& value : tree) std::cin >> value;

    std::cout << "Postorder traversal: ";
    if (tree.empty()) std::cout << "(empty)\n";
    else {
        postorder(tree, 0);
        std::cout << '\n';
    }
}
