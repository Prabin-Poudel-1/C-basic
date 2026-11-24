#include <iostream>
#include <new>
#include <sstream>
#include <string>

class LinkedListStack {
private:
    struct Node {
        int value;
        Node* next;
    };
    Node* top = nullptr;

public:
    ~LinkedListStack() {
        while (top != nullptr) {
            Node* oldTop = top;
            top = top->next;
            delete oldTop;
        }
    }

    void push(int value) {
        Node* newNode = new (std::nothrow) Node{value, top};
        if (newNode == nullptr) {
            std::cout << "Could not allocate a stack node.\n";
            return;
        }
        top = newNode;
        std::cout << "Pushed " << value << ".\n";
    }

    void pop() {
        if (top == nullptr) {
            std::cout << "Stack is empty.\n";
            return;
        }
        Node* oldTop = top;
        std::cout << "Popped " << oldTop->value << ".\n";
        top = top->next;
        delete oldTop;
    }

    void display() const {
        if (top == nullptr) {
            std::cout << "Stack is empty.\n";
            return;
        }
        std::cout << "Top to bottom: ";
        for (Node* current = top; current != nullptr; current = current->next) {
            std::cout << current->value << (current->next == nullptr ? "" : " ");
        }
        std::cout << '\n';
    }
};

int main() {
    LinkedListStack stack;
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
            } else {
                stack.push(value);
            }
        } else if (choice == "2") {
            stack.pop();
        } else if (choice == "3") {
            stack.display();
        } else {
            std::cout << "Choose 1, 2, 3, or 0.\n";
        }
    }
}
