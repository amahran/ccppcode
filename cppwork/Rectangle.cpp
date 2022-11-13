// Practice friend class
#include <cassert>

class Square {
public:
    Square(int side) : side_(side) {}
private:
    double side_;
    friend class Rectangle;
};

class Rectangle {
public:
    Rectangle(const Square& square);
    double Area() const;
private:
    double width_;
    double height_;
};

Rectangle::Rectangle(const Square& square) : width_(square.side_), height_(square.side_) {}

double Rectangle::Area() const {
    return width_ * height_;
}

int main () {
    Square square(5);
    Rectangle rectangle(square);
    assert(rectangle.Area() == 25);
}