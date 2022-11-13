#include <vector>
#include <cassert>

class Wheel {
public:
    Wheel() : diameter(50) {}
    float diameter;
};

class Car {
public:
    Car() : wheels(4, Wheel()) {};
    std::vector<Wheel> wheels; // Car has Wheels
};

int main() {
    Car car;

    assert(car.wheels.size() > 1);
}
