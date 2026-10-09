#include <cmath>
#include <iomanip>
#include <iostream>

// Calculate simple interest from principal, annual percentage rate, and years.
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

    // Simple interest does not earn additional interest on previous interest.
    double interest = principal * (rate / 100.0) * years;
    double total = principal + interest;
    if (!std::isfinite(interest) || !std::isfinite(total)) {
        std::cout << "Result is too large.\n";
        return 0;
    }
    std::cout << std::fixed << std::setprecision(2)
              << "Simple interest: " << interest << "\nTotal amount: " << total << '\n';
    return 0;
}
