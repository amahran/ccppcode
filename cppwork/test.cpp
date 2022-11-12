#include <string>
#include <cstring>
#include <iostream>

using namespace std;

class Car {
// TODO: Declare getter and setter for brand
public:
    void Brand(string s);
    string Brand() const;
// TODO: Declare private attributes
private:
    int horsepower_;
    int weight_;
    char *brand_;
};

// Define setters
void Car::Brand(string b) {
    brand_ = new char[b.length() + 1];
    strcpy(brand_, b.c_str());
}


// Define getters
string Car::Brand() const {
    return brand_;
}

// Test in main()
int main() 
{
    Car car;
    car.Brand("Peugeot");
    car.Brand("BMW");
    std::cout << car.Brand() << "\n";   
}