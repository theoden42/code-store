#include <iostream>

int main() {
    int a = 5;
    int b = ++a + a++ + --a;
    
    std::cout << "a = " << a << ", b = " << b << std::endl;

    return 0;
}