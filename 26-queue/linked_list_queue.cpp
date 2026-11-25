#include <iostream>
#include <new>
#include <sstream>
#include <string>

class LinkedListQueue {
private:
    struct Node {
        int value;
        Node* next;
    };
    Node* front = nullptr;
    Node* rear = nullptr;

public:
    ~LinkedListQueue() {
        while (front != nullptr) {
            Node* oldFront = front;
            front = front->next;
            delete oldFront;
        }
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* node = new (std::nothrow) Node{value, nullptr};
        if (node == nullptr) {
            std::cout << "Could not allocate a queue node.\n";
            return;
        }
        if (rear == nullptr) {
            front = node;
        } else {
            rear->next = node;
        }
        rear = node;
        std::cout << "Enqueued " << value << ".\n";
    }

    void dequeue() {
        if (front == nullptr) {
            std::cout << "Queue is empty.\n";
            return;
        }
        Node* oldFront = front;
        std::cout << "Dequeued " << oldFront->value << ".\n";
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete oldFront;
    }

    void display() const {
        if (front == nullptr) {
            std::cout << "Queue is empty.\n";
            return;
        }
        std::cout << "Front to rear: ";
        for (Node* current = front; current != nullptr; current = current->next) {
            std::cout << current->value << (current->next == nullptr ? "" : " ");
        }
        std::cout << '\n';
    }
};

int main() {
    LinkedListQueue queue;
    std::string choice;
    while (true) {
        std::cout << "1. Enqueue  2. Dequeue  3. Display  0. Exit\n";
        std::cout << "Choice: ";
        if (!std::getline(std::cin, choice)) {
            break;
        }
        if (choice == "0") {
            break;
        } else if (choice == "1") {
            std::string line;
            std::cout << "Integer to enqueue: ";
            if (!std::getline(std::cin, line)) {
                break;
            }
            std::istringstream valueInput(line);
            int value;
            std::string extra;
            if (!(valueInput >> value) || (valueInput >> extra)) {
                std::cout << "Enter a whole number.\n";
            } else {
                queue.enqueue(value);
            }
        } else if (choice == "2") {
            queue.dequeue();
        } else if (choice == "3") {
            queue.display();
        } else {
            std::cout << "Choose 1, 2, 3, or 0.\n";
        }
    }
}
