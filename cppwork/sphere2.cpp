#include <cassert>
#include <cmath>
#include <stdexcept>
#include <iostream>

// TODO: Define class Sphere
class Sphere {
 public:
    // Constructor
    Sphere(int r) : radius_(r) { 
        Validate();
    }
    // Accessors
    int Radius() const { return radius_; };
    // Mutators
    void Radius(int r) {
        radius_ = r;
        Validate();
    }
    static float Volume(int radius) {
        return (4/3.0) * pi * pow(radius, 3);
    }
 private:
    // Private members
    static float constexpr pi {3.14569};
    int radius_;
    void Validate() {
        if (radius_ < 0) throw std::invalid_argument("Radius has to be positive");
    }
};

// Test
int main(void) {
    bool caught = false;
    try {
        Sphere sphere(5);
        assert(sphere.Radius() == 5);
        assert(abs(Sphere::Volume( sphere.Radius() ) - 523.6) < 1);

        sphere.Radius(6);
        assert(sphere.Radius() == 6);
        assert(abs(Sphere::Volume( sphere.Radius() ) - 905.9) < 1);
        // std::cout << sphere.Volume();
    } catch (...) {
        caught = true;
    }
    assert(caught == false);

    try {
        Sphere sphere(-5);
    } catch (std::invalid_argument) {
        caught = true;
    }
    assert(caught == false);
}
