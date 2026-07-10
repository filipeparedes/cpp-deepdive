#include <iostream>
#include <concepts>

template <typename T>
concept Numeric = std::integral<T>; // || std::floating_point<T>;

template <Numeric T>
T add(T a, T b) {
    return a + b;
}

/*
    Objective: Constrain a template function using C++20 Concepts.
    Create a generic 'add' function that only accepts integral types 
    (e.g., int, long) and strictly rejects floating-point types 
    (e.g., float, double) at compile time.
*/
int main(){
    std::cout << "Int sum: " << add(10, 20) << std::endl;

    //should trigger a compile error
    //std::cout << "Double sum: " << add(5.5, 2.9) << std::endl;

    return 0;
}