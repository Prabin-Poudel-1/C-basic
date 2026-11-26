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

bool contains(Node* root, int value) {
    if (root == nullptr || root->value == value) {
        return root != nullptr;
    }
    return value < root->value ? contains(root->left, value) : contains(root->right, value);
}

Node* minimum(Node* root) {
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* erase(Node* root, int value) {
    if (root == nullptr) {
        return nullptr;
    }
    if (value < root->value) {
        root->left = erase(root->left, value);
    } else if (value > root->value) {
        root->right = erase(root->right, value);
    } else if (root->left == nullptr) {
        Node* right = root->right;
        delete root;
        return right;
    } else if (root->right == nullptr) {
        Node* left = root->left;
        delete root;
        return left;
    } else {
        Node* successor = minimum(root->right);
        root->value = successor->value;
        root->right = erase(root->right, successor->value);
    }
    return root;
}

void inOrder(Node* root, bool& first) {
    if (root != nullptr) {
        inOrder(root->left, first);
        if (!first) {
            std::cout << ' ';
        }
        std::cout << root->value;
        first = false;
        inOrder(root->right, first);
    }
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
    std::cout << "Value to delete: ";
    if (!std::getline(std::cin, line)) {
        std::cout << "A target value is required.\n";
        deleteTree(root);
        return 0;
    }
    std::istringstream targetInput(line);
    int target;
    if (!(targetInput >> target) || (targetInput >> extra)) {
        std::cout << "Enter a whole number to delete.\n";
        deleteTree(root);
        return 0;
    }
    const bool found = contains(root, target);
    root = erase(root, target);
    std::cout << (found ? "Deleted " + std::to_string(target) + " from the BST.\n"
                        : "Value not found; the BST was unchanged.\n");
    if (root == nullptr) {
        std::cout << "BST is empty.\n";
    } else {
        std::cout << "BST values in order: ";
        bool first = true;
        inOrder(root, first);
        std::cout << '\n';
    }
    deleteTree(root);
}
