#include <iostream>
#include <numeric>
int main() {
    #if __cplusplus >= 201703L
        std::cout << "C++17 supported. GCD: " << std::gcd(12, 18) << std::endl;
    #else
        std::cout << "C++17 not supported." << std::endl;
    #endif
    return 0;
}