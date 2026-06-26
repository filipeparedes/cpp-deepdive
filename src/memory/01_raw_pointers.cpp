#include <iostream>

void multiplyByTen(int* nPtr);

/*
    Write a program that allocates dynamic memory for two integers on the Heap, 
    modifies them using a function that takes raw pointers, swaps their targets, 
    and safely cleans up memory to ensure zero leaks.
 */
int main() {
    //allocate dynamic memory
    int* num = new int(10);
    int* num2 = new int(20);

    multiplyByTen(num);
    multiplyByTen(num2);

    std::cout << "num: " << *num << " at " << num << std::endl;
    std::cout << "num2: " << *num2 << " at " << num2 << std::endl;

    //swap targets
    int* temp = num;
    num = num2;
    num2 = temp;

    std::cout << "--- swap ---" << std::endl;

    std::cout << "num: " << *num << " at " << num << std::endl;
    std::cout << "num2: " << *num2 << " at " << num2 << std::endl;

    //free memory post usage
    delete num;
    delete num2;

    return 0;
}

void multiplyByTen(int* nPtr){
    *nPtr = *nPtr*10;
}