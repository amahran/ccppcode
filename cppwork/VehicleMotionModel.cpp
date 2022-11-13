// Practice overriding

#include <cassert>
#include <cmath>

#define PHI 1.61803
#define PI 3.14159

class Vehiclemodel {
    virtual void Move(double v, double phi) = 0;
};

class ParticleModel : public Vehiclemodel {
public:
    virtual void Move(double v, double phi);
    double x;
    double y;
    double theta;
};

class BicycleModel : public ParticleModel {
public:
    void Move(double v, double phi) override;
    double L = 1;
};

void ParticleModel::Move(double v, double phi) {
    theta += phi;
    x += v * cos(theta);
    y += v * cos(theta);
}

void BicycleModel::Move(double v, double phi) {
    theta += v / L *  tan(phi);
    x += v * cos(theta);
    y += v * cos(theta);
}

int main () {
 // Test function overriding
  ParticleModel particle;
  BicycleModel bicycle;
  particle.Move(10, PI / 9);
  bicycle.Move(10, PI / 9);
  assert(particle.x != bicycle.x);
  assert(particle.y != bicycle.y);
  assert(particle.theta != bicycle.theta);
}
