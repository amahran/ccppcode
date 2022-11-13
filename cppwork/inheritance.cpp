#include <iostream>

class Spicie {
    public:
        void Talk() { std::cout << "Can't talk\n"; }
};

class Animal : public Spicie {
    public:
        void Talk() { std::cout << "Talk\n"; }
};

class Dog : private Animal {
    public:
        void Walk() { std::cout << "I'm walking\n"; }
        void Talk(std::string content) { 
            Animal::Talk(); 
            std::cout << content << std::endl;
        }
};

class Cat : public Animal {
    public:
        void Talk() { std::cout << "Neyaw\n"; }
};

class Bird : public Animal {};

int main() {
    Animal animal;
    animal.Talk();
    Dog dog;
    dog.Talk("HawHaw");
    Cat cat;
    cat.Talk();

    Bird bird;
    bird.Talk();
}
