#include <stdlib.h>
#include <iostream>

class MyClass
{
private:
    static float constexpr pi = 3.14;
};


int main()
{
    // allocate memory using malloc
    // comment these lines out to run the example below
    // MyClass *myClass = (MyClass *)malloc(sizeof(MyClass));
    // myClass->setNumber(42); // EXC_BAD_ACCESS
    // free(myClass);
	  
	// allocate memory using new
    // MyClass myClass;
    // myClass.setNumber(42); // works as expected
    // delete myClass;
    std::unique_ptr<int> unique = std::make_unique<int>(); // create a unique pointer on the stack
    *unique = 2; // assign a value
    // delete is not neccessary
    // std::unique_ptr<int> p = unique; // Not allowed
    std::unique_ptr<int> p = std::move(unique);
    return 0;
}
