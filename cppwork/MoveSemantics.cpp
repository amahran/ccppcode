#include <stdlib.h>
#include <iostream>

class MyMovableClass
{
private:
    int _size;
    int *_data;

public:
    MyMovableClass(size_t size) // constructor
    {
        _size = size;
        _data = new int[_size];
        std::cout << "CREATING instance of MyMovableClass at " << this << " allocated with size = " << _size*sizeof(int)  << " bytes" << std::endl;
    }

    ~MyMovableClass() // 1 : destructor
    {
        std::cout << "DELETING instance of MyMovableClass at " << this << std::endl;
        delete[] _data;
    }
    
    MyMovableClass(const MyMovableClass &source) // 2 : copy constructor
    {
        _size = source._size;
        _data = new int[_size];
        *_data = *source._data;
        std::cout << "COPYING content of instance " << &source << " to instance " << this << std::endl;
    }
    
    MyMovableClass &operator=(const MyMovableClass &source) // 3 : copy assignment operator
    {
        std::cout << "ASSIGNING content of instance " << &source << " to instance " << this << std::endl;
        if (this == &source) // Protection against self-assignment
            return *this;
        delete[] _data;
        _data = new int[source._size];
        *_data = *source._data;
        _size = source._size;
        return *this;
    }

    MyMovableClass(MyMovableClass &&source) // 4 : move constructor
    {
        std::cout << "MOVING content of instance " << &source << " to instance " << this << std::endl;
        _size = source._size;
        _data = source._data;

        source._data = nullptr;
        source._size = 0;
    }
    
    MyMovableClass &operator=(MyMovableClass &&source) // 5 : move assignment operator
    {
        std::cout << "MOVING (assign) content of instance " << &source << " to instance " << this << std::endl;
        if (this == &source) // Protection against self-assignment
            return *this;
        delete[] _data;
        _data = source._data;
        _size = source._size;

        source._data = nullptr;
        source._size = 0;

        return *this;
    }
};

MyMovableClass createObject(int size){
  MyMovableClass obj(size); // regular constructor
  return obj; // return MyMovableClass object by value
}

void useObject(MyMovableClass obj)
{
    std::cout << "using object " << &obj << std::endl;
}

int main()
{
    // MyMovableClass obj1 = MyMovableClass(10); // copy assignment operator
    // MyMovableClass obj2(obj1); // copy constructor
    // obj2 = MyMovableClass(10); // copy assignment operator

    // MyMovableClass obj3 = obj1;
    // MyMovableClass obj4(2);
    // obj4 = createObject(3); // Special Call to the copy constructor
    // MyMovableClass obj1(10); // regular constructor
    // as it's called for a temporary object

    MyMovableClass obj1(100); // constructor

    useObject(obj1);
    useObject(MyMovableClass(200));

    return 0;
}
// CREATING instance of MyMovableClass at 0x7ff7b1a7d478 allocated with size = 400 bytes
// COPYING content of instance 0x7ff7b1a7d478 to instance 0x7ff7b1a7d468
// using object 0x7ff7b1a7d468
// DELETING instance of MyMovableClass at 0x7ff7b1a7d468
// CREATING instance of MyMovableClass at 0x7ff7b1a7d438 allocated with size = 800 bytes
// MOVING content of instance 0x7ff7b1a7d438 to instance 0x7ff7b1a7d448
// using object 0x7ff7b1a7d448
// DELETING instance of MyMovableClass at 0x7ff7b1a7d448
// DELETING instance of MyMovableClass at 0x7ff7b1a7d438
// DELETING instance of MyMovableClass at 0x7ff7b1a7d478