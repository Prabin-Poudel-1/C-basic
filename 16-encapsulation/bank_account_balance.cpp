#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class BankAccount {
private:
    double balance;

public:
    explicit BankAccount(double initialBalance) : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    bool deposit(double amount) {
        if (!std::isfinite(amount) || amount < 0 || !std::isfinite(balance + amount)) {
            return false;
        }
        balance += amount;
        return true;
    }

    bool withdraw(double amount) {
        if (!std::isfinite(amount) || amount < 0 || amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }
};

bool readAmount(const std::string& line, double& amount) {
    std::istringstream input(line);
    std::string extra;
    return (input >> amount) && !(input >> extra) && std::isfinite(amount) && amount >= 0;
}

int main() {
    std::string line;
    double initial;
    double deposit;
    double withdrawal;

    std::cout << "Enter initial balance: ";
    if (!std::getline(std::cin, line) || !readAmount(line, initial)) {
        std::cout << "Amounts must be finite and non-negative.\n";
        return 0;
    }
    BankAccount account(initial);
    std::cout << "Enter deposit amount: ";
    if (!std::getline(std::cin, line) || !readAmount(line, deposit) || !account.deposit(deposit)) {
        std::cout << "Deposit amount is invalid.\n";
        return 0;
    }
    std::cout << "Enter withdrawal amount: ";
    if (!std::getline(std::cin, line) || !readAmount(line, withdrawal)) {
        std::cout << "Amounts must be finite and non-negative.\n";
        return 0;
    }
    if (!account.withdraw(withdrawal)) {
        std::cout << "Withdrawal declined: insufficient balance.\n";
    } else {
        std::cout << "Withdrawal successful.\n";
    }
    std::cout << std::fixed << std::setprecision(2) << "Balance: " << account.getBalance() << '\n';
}
