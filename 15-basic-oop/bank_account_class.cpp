#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class BankAccount {
public:
    std::string holder;
    std::string accountNumber;
    double balance;

    void deposit(double amount) {
        balance += amount;
    }

    bool withdraw(double amount) {
        if (amount > balance) {
            return false;
        }
        balance -= amount;
        return true;
    }

    void displayBalance() const {
        std::cout << std::fixed << std::setprecision(2)
                  << "Current balance: " << balance << '\n';
    }
};

bool readNonNegativeNumber(const std::string& line, double& value) {
    std::istringstream input(line);
    std::string extra;
    return (input >> value) && !(input >> extra) && std::isfinite(value) && value >= 0;
}

int main() {
    BankAccount account;
    std::string line;
    double deposit;
    double withdrawal;

    std::cout << "Enter account holder: ";
    if (!std::getline(std::cin, account.holder) || account.holder.empty()) {
        std::cout << "Account holder cannot be empty.\n";
        return 0;
    }
    std::cout << "Enter account number: ";
    if (!std::getline(std::cin, account.accountNumber) || account.accountNumber.empty()) {
        std::cout << "Account number cannot be empty.\n";
        return 0;
    }
    std::cout << "Enter initial balance: ";
    if (!std::getline(std::cin, line) || !readNonNegativeNumber(line, account.balance)) {
        std::cout << "Balance and transaction amounts must be finite non-negative numbers.\n";
        return 0;
    }
    std::cout << "Enter deposit amount: ";
    if (!std::getline(std::cin, line) || !readNonNegativeNumber(line, deposit) ||
        !std::isfinite(account.balance + deposit)) {
        std::cout << "Balance and transaction amounts must be finite non-negative numbers.\n";
        return 0;
    }
    account.deposit(deposit);

    std::cout << "Enter withdrawal amount: ";
    if (!std::getline(std::cin, line) || !readNonNegativeNumber(line, withdrawal)) {
        std::cout << "Balance and transaction amounts must be finite non-negative numbers.\n";
        return 0;
    }

    std::cout << "Account holder: " << account.holder << '\n';
    std::cout << "Account number: " << account.accountNumber << '\n';
    account.displayBalance();
    if (!account.withdraw(withdrawal)) {
        std::cout << "Withdrawal declined: insufficient balance.\n";
    } else {
        std::cout << "Withdrawal successful.\n";
    }
    account.displayBalance();
}
