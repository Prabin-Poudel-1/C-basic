#include <iostream>
#include <new>
#include <sstream>
#include <string>

struct Node {
    int value;
    Node* left;
    Node* right;
};

Node* insert(Node* root, int value) {
    if (root == nullptr) {
        return new (std::nothrow) Node{value, nullptr, nullptr};
    }
    if (value < root->value) {
        root->left = insert(root->left, value);
    } else if (value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}

bool search(Node* root, int target) {
    if (root == nullptr) {
        return false;
    }
    if (root->value == target) {
        return true;
    }
    return target < root->value ? search(root->left, target) : search(root->right, target);
}

void deleteTree(Node* root) {
    if (root != nullptr) {
        deleteTree(root->left);
        deleteTree(root->right);
        delete root;
    }
}

int main() {
    std::string line;
    std::cout << "Number of BST values (0 to 100): ";
    if (!std::getline(std::cin, line)) {
        std::cout << "A count is required.\n";
        return 0;
    }
    std::istringstream countInput(line);
    int count;
    std::string extra;
    if (!(countInput >> count) || (countInput >> extra) || count < 0 || count > 100) {
        std::cout << "Enter a whole number from 0 to 100.\n";
        return 0;
    }

    Node* root = nullptr;
    for (int i = 0; i < count; ++i) {
        std::cout << "Value " << (i + 1) << ": ";
        if (!std::getline(std::cin, line)) {
            std::cout << "Tree input ended early.\n";
            deleteTree(root);
            return 0;
        }
        std::istringstream valueInput(line);
        int value;
        if (!(valueInput >> value) || (valueInput >> extra)) {
            std::cout << "Enter a whole number for every value.\n";
            deleteTree(root);
            return 0;
        }
        root = insert(root, value);
    }
    std::cout << "Value to search: ";
    if (!std::getline(std::cin, line)) {
        std::cout << "A search value is required.\n";
        deleteTree(root);
        return 0;
    }
    std::istringstream targetInput(line);
    int target;
    if (!(targetInput >> target) || (targetInput >> extra)) {
        std::cout << "Enter a whole number to search.\n";
        deleteTree(root);
        return 0;
    }
    std::cout << (search(root, target) ? "Value found in the BST.\n" : "Value not found in the BST.\n");
    deleteTree(root);
}
