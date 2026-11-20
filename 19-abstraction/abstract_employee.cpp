#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

class Employee {
public:
    explicit Employee(std::string name) : name_(std::move(name)) {}
    virtual ~Employee() = default;

    virtual double calculateMonthlyPay() const = 0;

    void displayPay() const {
        std::cout << name_ << "'s monthly pay: " << std::fixed
                  << std::setprecision(2) << calculateMonthlyPay() << '\n';
    }

private:
    std::string name_;
};

class SalariedEmployee : public Employee {
public:
    SalariedEmployee(std::string name, double monthlySalary)
        : Employee(std::move(name)), monthlySalary_(monthlySalary) {}

    double calculateMonthlyPay() const override {
        return monthlySalary_;
    }

private:
    double monthlySalary_;
};

int main() {
    std::string name;
    double salary;
    std::cout << "Enter employee name: ";
    if (!std::getline(std::cin, name) || name.find_first_not_of(" \t\r") == std::string::npos) {
        std::cout << "Please enter a name and a finite, non-negative salary.\n";
        return 0;
    }

    std::cout << "Enter monthly salary: ";
    std::string extraInput;
    if (!(std::cin >> salary) || (std::cin >> extraInput)
            || !std::isfinite(salary) || salary < 0) {
        std::cout << "Please enter a name and a finite, non-negative salary.\n";
        return 0;
    }

    SalariedEmployee employee(name, salary);
    employee.displayPay();
}
