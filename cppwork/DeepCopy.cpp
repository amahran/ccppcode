#include <iostream>
#include <cstdlib>

class DeepCopy {
private:
    int *_myInt;
public:
    DeepCopy(int val) {
        _myInt = (int *)malloc(sizeof(int));
        *_myInt = val;
        std::cout << "Resource allocated at address: " << _myInt << std::endl;
    }
    ~DeepCopy() {
        free(_myInt);
        std::cout << "Resource freed at address: " << _myInt << std::endl;
    }
    DeepCopy(DeepCopy &source) {
        _myInt = (int *)malloc(sizeof(int));
        *_myInt = *(source._myInt);
        std::cout << "resource allocated at address " << _myInt << " with _myInt = " << *_myInt << std::endl;
    }
    DeepCopy &operator=(DeepCopy &source) {
        _myInt = (int *)malloc(sizeof(int));
        std::cout << "Resource allocated at address " << _myInt << " with _myInt=" << *_myInt << std::endl;
        *_myInt = *source._myInt;
        return *this;
    }
};

int main()
{
    DeepCopy source(42);
    DeepCopy dest1(source);
    DeepCopy dest2 = dest1; // Will call teh copy constructor also

    return 0;
}
