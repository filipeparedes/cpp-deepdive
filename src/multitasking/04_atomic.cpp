#include <iostream>
#include <thread>
#include <atomic>

void atomicIncrement();

std::atomic<int> atomicCounter{0};

/*
    Demonstrate lock-free thread safety using std::atomic.
    Compare its syntax and concept to the heavy mutex approach.
*/
int main() {
    std::thread t1(atomicIncrement);
    std::thread t2(atomicIncrement);
    t1.join();
    t2.join();

    std::cout << "Counter: " << atomicCounter << std::endl;
}

void atomicIncrement(){
    for(int i=0; i<1000000; i++){
        //No need for extra lock instructions, it's done automatically by the CPU
        atomicCounter++;
    }
}