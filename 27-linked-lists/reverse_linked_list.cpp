#include <iostream>
#include <new>
#include <sstream>
#include <string>

struct Node {
    int value;
    Node* next;
};

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* next = head->next;
        delete head;
        head = next;
    }
}

int main() {
    std::string line;
    std::cout << "Number of values (0 to 100): ";
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

    Node* head = nullptr;
    Node* tail = nullptr;
    for (int i = 0; i < count; ++i) {
        std::cout << "Value " << (i + 1) << ": ";
        if (!std::getline(std::cin, line)) {
            std::cout << "List input ended early.\n";
            deleteList(head);
            return 0;
        }
        std::istringstream valueInput(line);
        int value;
        if (!(valueInput >> value) || (valueInput >> extra)) {
            std::cout << "Enter a whole number for every list value.\n";
            deleteList(head);
            return 0;
        }
        Node* node = new (std::nothrow) Node{value, nullptr};
        if (node == nullptr) {
            std::cout << "Could not allocate a list node.\n";
            deleteList(head);
            return 0;
        }
        if (head == nullptr) {
            head = node;
        } else {
            tail->next = node;
        }
        tail = node;
    }

    Node* previous = nullptr;
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }
    head = previous;

    if (head == nullptr) {
        std::cout << "The list is empty.\n";
    } else {
        std::cout << "Reversed list: ";
        for (Node* node = head; node != nullptr; node = node->next) {
            std::cout << node->value << (node->next == nullptr ? "" : " -> ");
        }
        std::cout << " -> null\n";
    }
    deleteList(head);
}
