#include <cmath>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

struct Employee {
    std::string name;
    int employeeId;
    double monthlySalary;
};

bool parsePositiveId(const std::string& line, int& id) {
    std::istringstream input(line);
    std::string extra;
    return (input >> id) && !(input >> extra) && id > 0;
}

bool parseSalary(const std::string& line, double& salary) {
    std::istringstream input(line);
    std::string extra;
    return (input >> salary) && !(input >> extra) && std::isfinite(salary) && salary >= 0;
}

int main() {
    Employee employee;
    std::string line;

    std::cout << "Enter employee name: ";
    if (!std::getline(std::cin, employee.name)
        || employee.name.find_first_not_of(" \t") == std::string::npos) {
        std::cout << "A name is required.\n";
        return 0;
    }
    std::cout << "Enter employee ID: ";
    if (!std::getline(std::cin, line) || !parsePositiveId(line, employee.employeeId)) {
        std::cout << "ID must be positive and salary must be non-negative.\n";
        return 0;
    }
    std::cout << "Enter monthly salary: ";
    if (!std::getline(std::cin, line) || !parseSalary(line, employee.monthlySalary)) {
        std::cout << "ID must be positive and salary must be non-negative.\n";
        return 0;
    }

    std::cout << "Employee information:\n";
    std::cout << "Name: " << employee.name << '\n';
    std::cout << "Employee ID: " << employee.employeeId << '\n';
    std::cout << "Monthly salary: " << std::fixed << std::setprecision(2)
              << employee.monthlySalary << '\n';
}
