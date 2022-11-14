#include <cassert>

// It is mandatory to put the template<> tag before the function signature, 
// to specify and mark that the declaration is generic.
template <typename T> // or template <class T> 
T Max(T a, T b) {
    return a > b ? a : b;
}

int main(){
    assert(Max<int>(2, 4) == 4);
    assert(Max<float>(-1.0, -2.3) == -1.0);
    assert(Max<char>('a', 'b') == 'b');
}
