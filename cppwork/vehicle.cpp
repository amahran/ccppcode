#include <cassert>
#include <iostream>
#include <string>

using std::string;

class Vehicle {
public:
  int wheels = 0;
  string color = "blue";
  int horsePower = 20;

  void Print() const
  {
    std::cout << "This " << color << " vehicle has " << wheels << " wheels and " << horsePower << " horse power!\n";
  }
};

class Scooter : public Vehicle {
    public:
        bool electric = false;
};

class Car : public Vehicle {
public:
  bool sunroof = false;
};

class Bicycle : public Vehicle {
public:
  bool kickstand = true;
};

int main() 
{
    Car car;
    car.wheels = 4;
    car.sunroof = true;
    car.Print();
    if(car.sunroof)
        std::cout << "And a sunroof!\n";

    Scooter scooter;
    scooter.horsePower = 5;
    scooter.wheels = 2;
    scooter.electric = true;
    scooter.Print();
    if (scooter.electric)
        std::cout << "And Electric!\n";

};