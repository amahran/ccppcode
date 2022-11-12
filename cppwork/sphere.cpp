#include <cassert>
#include <cmath>
#include <stdexcept>

// TODO: Define class Sphere
class Sphere {
 public:
    // Constructor
    Sphere(int r) : radius_(r), volume_((4/3.0) * pi * pow(radius_, 3)) {
        if (radius_ < 0) throw std::invalid_argument("Radius has to be positive");
    }
    // Accessors
    int Radius() const { return radius_; };
    float Volume() { return volume_; }
 private:
    // Private members
    float const pi {3.14569};
    int const radius_;
    float const volume_; // volume_ has to be defined last because it's using both pi and radius
    // Because the initializer list is initialized in oder of data members order of declaration
    // i.e. if volume is declared first, then it will be inialized first therefore it will see
    // rasius and pi as not yet initialized
    // See https://en.cppreference.com/w/cpp/language/constructor --> Initialization order
};

// Test
int main(void) {
    Sphere sphere(5);
    assert(sphere.Radius() == 5);
    assert(abs(sphere.Volume() - 523.6) < 1);
}