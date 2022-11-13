#include <cassert>
#include <iostream>
// Practice inheritance
#include <string>

using std::string;

class Animal {
public:
    string color;
    string name;
    int age;
};

class Snake : public Animal {
public:
    int length;
    void MakeSound(string sound) { std::cout << sound << std::endl; }
};

class Cat : public Animal {
public:
    int height;
    void MakeSound(string sound) { std::cout << sound << std::endl; }
};


int main() {
    Cat cat;
    cat.color = "Black Yellow";
    cat.name = "Ms. Mean";
    cat.age = 3;
    cat.MakeSound("Meyaaaaew");

    Snake snake;
    snake.color = "Yellow";
    snake.name = "Mr. Poisin";
    snake.age = 1;
    snake.MakeSound("Feyaaaaw");
}
