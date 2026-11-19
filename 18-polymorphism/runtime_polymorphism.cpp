#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

class Shape {
public:
    virtual ~Shape() = default;
    virtual double area() const = 0;
};

class Circle : public Shape {
public:
    explicit Circle(double radius) : radius_(radius) {}

    double area() const override {
        return 3.141592653589793 * radius_ * radius_;
    }

private:
    double radius_;
};

class Rectangle : public Shape {
public:
    Rectangle(double length, double width) : length_(length), width_(width) {}

    double area() const override {
        return length_ * width_;
    }

private:
    double length_;
    double width_;
};

int main() {
    double radius, length, width;
    std::string extraInput;
    std::cout << "Enter circle radius, rectangle length, and width: ";
    if (!(std::cin >> radius >> length >> width) || (std::cin >> extraInput)
            || !std::isfinite(radius) || !std::isfinite(length) || !std::isfinite(width)
            || radius < 0 || length < 0 || width < 0) {
        std::cout << "Please enter three finite, non-negative numbers.\n";
        return 0;
    }

    Circle circle(radius);
    Rectangle rectangle(length, width);
    const Shape* shapes[] = {&circle, &rectangle};
    const double circleArea = shapes[0]->area();
    const double rectangleArea = shapes[1]->area();
    if (!std::isfinite(circleArea) || !std::isfinite(rectangleArea)) {
        std::cout << "The calculated area is too large.\n";
        return 0;
    }

    std::cout << std::fixed << std::setprecision(2)
              << "Circle area: " << circleArea
              << "\nRectangle area: " << rectangleArea << '\n';
}
