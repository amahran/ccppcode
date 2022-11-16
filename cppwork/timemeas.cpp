// Time measurement
#include <chrono>
#include <iostream>

int main () {
    const int size = 1000;
    static int x[size][size];

    auto t1 = std::chrono::high_resolution_clock::now();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            x[i][j] = i + j; // Interchanging j & i in the assignemnt will slow down the cache access and tehrefore the program
            // std::cout << &x[i][j] << ": i = " << i << ", j = " << j << std::endl;
        }
    }

    auto t2 = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(t2 - t1).count();
    std::cout << "Execution time: " << duration << " microseconds\n";
}
