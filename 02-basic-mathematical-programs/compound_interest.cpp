#include <cmath>
#include <iomanip>
#include <iostream>

// Calculate compound interest assuming annual compounding.
int main() {
    double principal, rate, years;
    std::cout << "Enter principal, annual rate (%), and time (years): ";
    if (!(std::cin >> principal >> rate >> years)) {
        std::cout << "Invalid input.\n";
        return 0;
    }
    if (!std::isfinite(principal) || !std::isfinite(rate) || !std::isfinite(years)
        || principal < 0 || rate < 0 || years < 0) {
        std::cout << "Inputs must be finite and non-negative.\n";
        return 0;
    }

    // Annual compounding: amount = principal * (1 + rate / 100) ^ years.
    double amount = principal == 0 ? 0 : principal * std::pow(1 + rate / 100.0, years);
    double interest = amount - principal;
    if (!std::isfinite(amount) || !std::isfinite(interest)) {
        std::cout << "Result is too large.\n";
        return 0;
    }
    std::cout << std::fixed << std::setprecision(2)
              << "Compound interest: " << interest << "\nTotal amount: " << amount << '\n';
    return 0;
}
