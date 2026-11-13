#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

class Employee {
public:
    std::string name;
    int id;
    double monthlySalary;

    double annualSalary() const {
        return monthlySalary * 12;
    }

    void displayDetails() const {
        std::cout << "Employee details:\n";
        std::cout << "Name: " << name << '\n';
        std::cout << "ID: " << id << '\n';
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "Monthly salary: " << monthlySalary << '\n';
        std::cout << "Annual salary: " << annualSalary() << '\n';
    }
};

bool readPositiveInteger(const std::string& line, int& value) {
    std::istringstream input(line);
    std::string extra;
    return (input >> value) && !(input >> extra) && value > 0;
}

bool readNonNegativeNumber(const std::string& line, double& value) {
    std::istringstream input(line);
    std::string extra;
    return (input >> value) && !(input >> extra) && std::isfinite(value) && value >= 0;
}

int main() {
    Employee employee;
    std::string line;

    std::cout << "Enter employee name: ";
    if (!std::getline(std::cin, employee.name) || employee.name.empty()) {
        std::cout << "Employee name cannot be empty.\n";
        return 0;
    }
    std::cout << "Enter positive employee ID: ";
    if (!std::getline(std::cin, line) || !readPositiveInteger(line, employee.id)) {
        std::cout << "ID must be a positive whole number.\n";
        return 0;
    }
    std::cout << "Enter non-negative monthly salary: ";
    if (!std::getline(std::cin, line) || !readNonNegativeNumber(line, employee.monthlySalary) ||
        !std::isfinite(employee.annualSalary())) {
        std::cout << "Salary must be a finite non-negative number.\n";
        return 0;
    }

    employee.displayDetails();
}
