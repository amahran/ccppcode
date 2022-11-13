#include <iostream>

class Animal {
public:
    virtual void Talk() = 0;
};

class Human : public Animal {
public:
    void Talk() {std::cout << "Hello\n"; }
};

int main() {
    Human human;
    human.Talk();
}