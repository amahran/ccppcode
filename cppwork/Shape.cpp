// Practice virtual functions 

#include <cassert>

class Shape {
public:
    virtual double Area() const = 0;
};

class Square : public Shape {
public:
    Square(double side) : side_(side) {}
    double Area() const override { return side_*side_; }
private:
    double side_;
};

int main() {
    Square square(3); 
    assert(square.Area() == 9);
}
