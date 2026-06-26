#include <iostream>
#include <string>

void swapValues(int& ref1, int& ref2);
void printStatus(const std::string& label, const int value);

/*
    Write a program that swaps the values of two local integers using references 
    (instead of pointers), and then passes them to a read-only tracking function 
    that enforces safety using const.
*/
int main() {
    int a=5, b=10;

    printStatus("a", a);
    printStatus("b", b);

    swapValues(a, b);

    std::cout << "--- swap ---" << std::endl;

    printStatus("a", a);
    printStatus("b", b);

}

void swapValues(int& ref1, int& ref2){
    int temp = ref1;
    ref1 = ref2;
    ref2 = temp;
}

/* 
    unlike label, which is a string, and occupies a large amount of memory,
    passing the int by value is actually a little bit faster, due to 
    integers occupying 4 bytes, and "references" occupying 8 bytes.
    "const" for local safety only
*/
void printStatus(const std::string& label, const int value){
    std::cout << label << ": " << value << std::endl;
    //value = 0; not possible due to "const"
}