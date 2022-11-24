#include <cstdlib>
#include <iostream>

class MyClass {
public:
    MyClass() {
        _myInt = (int *)malloc(sizeof(int));
    }
    ~MyClass() {
        free(_myInt);
    }
    void PrintOwnAddress() {
        std::cout << "Own address on the stack is " << this << std::endl;
    }
    void PrintMemeberAddress() {
        std::cout << "Mananging memory block on the heap at " << _myInt << std::endl;
    }

private:
    int *_myInt;
};


int main() {
    // Instantiate object 1
    MyClass myClass1;
    myClass1.PrintOwnAddress();
    myClass1.PrintMemeberAddress();

    // copy object 1 into object 2
    MyClass myClass2(myClass1); // Invokes the default copy constructor -> Shallow copy
    myClass2.PrintOwnAddress();
    myClass2.PrintMemeberAddress(); // This will print the same address!!!
}
