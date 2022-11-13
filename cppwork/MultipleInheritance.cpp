#include <cassert>
#include <iostream>

class Car {
public:
    std::string Drive() { return "I'm driving!"; }
};

class Boat {
public:
    std::string Cruise() { return "I'm cruising!"; }
};

class AmphibiousCar : public Car, public Boat {};

int main () {
    Car car;
    Boat boat;
    AmphibiousCar amphibiousCar;
    assert(amphibiousCar.Drive() == car.Drive());
    assert(amphibiousCar.Cruise() == boat.Cruise());
}
