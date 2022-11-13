// Practice Composition

#include <cassert>
#include <cmath>
#include <iostream>

#define PI M_PI 

class LineSegment { // Can also be a struct
public: 
    double length;
};

class Circle {
public:
    Circle(LineSegment& r) : radius_(r) {} // reference meember must be explicitly assigned in the constructor

    void Radius(double r) { radius_.length = r; }
    double Area() { return PI * pow(radius_.length , 2); }

private:
    LineSegment& radius_;
};


int main() {
    LineSegment raius {3}; // Uses a default constructor of assignment
    Circle circle(raius);
    circle.Radius(5);
    // std::cout << circle.Area() << std::endl;
    assert(abs(circle.Area() - 78.54) < 1);
}
