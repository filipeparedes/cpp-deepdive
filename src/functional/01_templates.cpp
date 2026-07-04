#include <iostream>

template <typename T>
T add(T a, T b) {
    return a + b;
}

/*
    Create a generic function blueprint using templates that can
    calculate and return the sum of two variables of the same arbitrary type
*/
int main(){
    std::cout << "Int: " << add(10, 12) << std::endl;
    std::cout << "Double: " << add(0.12, 9.0) << std::endl;
    std::cout << "Char: " << add('t', 'p') << std::endl;
    std::cout << "Bool: " << add(true, false) << std::endl;
}