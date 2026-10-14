#include <iostream>
#include <limits>
#include <sstream>
#include <string>

// Read exactly one integer per line, rejecting decimals and extra tokens.
template <typename T>
bool readValue(T& value) {
    std::string line;
    if (!std::getline(std::cin, line)) return false;
    std::istringstream input(line);
    char extra;
    return (input >> value) && !(input >> extra);
}

// In-memory ATM practice with whole currency units and a switch menu.
int main() {
    long long balance = 1000;
    while (true) {
        std::cout << "1. Balance\n2. Deposit\n3. Withdraw\n0. Exit\nChoice: ";
        int choice;
        if (!readValue(choice)) {
            std::cout << "Invalid input.\n";
            return 0;
        }
        switch (choice) {
            case 0:
                std::cout << "Goodbye.\n";
                return 0;
            case 1:
                std::cout << "Balance: " << balance << '\n';
                break;
            case 2: {
                std::cout << "Deposit amount (whole units): ";
                long long amount;
                if (!readValue(amount)) {
                    std::cout << "Invalid input.\n";
                    return 0;
                }
                if (amount <= 0) {
                    std::cout << "Amount must be positive.\n";
                } else if (amount > std::numeric_limits<long long>::max() - balance) {
                    std::cout << "Deposit would exceed the balance limit.\n";
                } else {
                    balance += amount;
                    std::cout << "Balance: " << balance << '\n';
                }
                break;
            }
            case 3: {
                std::cout << "Withdrawal amount (whole units): ";
                long long amount;
                if (!readValue(amount)) {
                    std::cout << "Invalid input.\n";
                    return 0;
                }
                if (amount <= 0) {
                    std::cout << "Amount must be positive.\n";
                } else if (amount > balance) {
                    std::cout << "Insufficient balance.\n";
                } else {
                    balance -= amount;
                    std::cout << "Balance: " << balance << '\n';
                }
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
        }
    }
}
