// Practice templates - type deduction

#include <cassert>

template <typename T>
T Average(T x, T y) {
    return (x + y) / 2;
}


int main() {
    assert(Average(2, 4) == 3);
}
