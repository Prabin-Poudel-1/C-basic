#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

class ComplexNumber {
public:
    ComplexNumber(double real, double imaginary) : real_(real), imaginary_(imaginary) {}

    ComplexNumber operator+(const ComplexNumber& other) const {
        return ComplexNumber(real_ + other.real_, imaginary_ + other.imaginary_);
    }

    void display() const {
        std::cout << std::fixed << std::setprecision(2) << real_
                  << (imaginary_ < 0 ? " - " : " + ")
                  << std::abs(imaginary_) << "i\n";
    }

    bool hasFiniteParts() const {
        return std::isfinite(real_) && std::isfinite(imaginary_);
    }

private:
    double real_;
    double imaginary_;
};

int main() {
    double firstReal, firstImaginary, secondReal, secondImaginary;
    std::cout << "Enter real and imaginary parts of both numbers: ";
    if (!(std::cin >> firstReal >> firstImaginary >> secondReal >> secondImaginary)) {
        std::cout << "Please enter four finite numbers.\n";
        return 0;
    }
    std::string extraInput;
    if ((std::cin >> extraInput) || !std::isfinite(firstReal)
            || !std::isfinite(firstImaginary) || !std::isfinite(secondReal)
            || !std::isfinite(secondImaginary)) {
        std::cout << "Please enter four finite numbers.\n";
        return 0;
    }

    ComplexNumber sum = ComplexNumber(firstReal, firstImaginary)
            + ComplexNumber(secondReal, secondImaginary);
    if (!sum.hasFiniteParts()) {
        std::cout << "The sum is too large to display.\n";
        return 0;
    }
    std::cout << "Sum: ";
    sum.display();
}
